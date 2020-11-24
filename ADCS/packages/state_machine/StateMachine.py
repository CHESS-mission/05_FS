from statemachine import StateMachine, State


class ADCSStateMachine(StateMachine):
    low_orbit = State('Low orbit', initial=True)
    middle_orbit = State('Middle orbit')
    high_orbit = State('High orbit')

    up_middle = low_orbit.to(middle_orbit)
    up_high = middle_orbit.to(high_orbit)
    down_middle = high_orbit.to(middle_orbit)
    down_low = middle_orbit.to(low_orbit)

    param = 10
    CRC_POLY = 0x91
    CRC8Table = [0] * 256

    for i in range(256):
        val = i
        for j in range(8):
            if val & 1:
                val ^= CRC_POLY
            val >>= 1
        CRC8Table[i] = val

    def __str__(self):
        return f"{self.current_state} set, param = {self.param}"

    def switcher(self, case):
        data = 0x00
        if case == 0:
            self.up_middle()
        elif case == 1:
            self.up_high()
        elif case == 2:
            self.down_middle()
        elif case == 3:
            self.down_low()
        else:
            print("error orbit")
            data = 0x03
        return data

    def on_enter_low_orbit(self):
        self.param = 10
        print(f"{self.current_state} set, param = {self.param}")

    def on_enter_middle_orbit(self):
        self.param = 20
        print(f"{self.current_state} set, param = {self.param}")

    def on_enter_high_orbit(self):
        self.param = 30
        print(f"{self.current_state} set, param = {self.param}")

    def request(self, data):
        return_data = ADCSStateMachine.create_return_packet(data[2])
        if data[0] == 0x1F and data[1] == 0x7F:
            if data[2] < 128:
                print('Telecommand packet')
                if data[-3] == 0x1F and data[-2] == 0xFF:
                    if ADCSStateMachine.checksum(data[:-1]) == data[-1]:
                        print("Telecommand packet OK")
                        return_data += self.exec_command(data[2])
                    else:
                        print("CRC error")
                        return_data += bytearray([0x04])
                else:
                    print("error in  Telecommand End message or Data byte bytes")
            else:
                print('Telemetry packet')
                if data[-2] == 0x1F and data[-1] == 0xFF:
                    print("Telemetry packet OK")
                    return_data += self.request_telemetry_data(data[2])
                else:
                    print("error in  Telecommand End message or Data byte bytes")

                return ADCSStateMachine.end_packet(return_data)
        else:
            print("error in Start message or Data byte bytes")

        return ADCSStateMachine.end_packet(return_data)

    @staticmethod
    def create_return_packet(id):
        return bytearray([0x1F, 0x7F, id])

    @staticmethod
    def end_packet(data):
        return data + bytearray([0x1F, 0xFF])

    @staticmethod
    def checksum(array):
        crc = 0
        for b in array:
            crc = ADCSStateMachine.CRC8Table[crc ^ b]
        return crc

    def exec_command(self, id):
        try:
            data = self.switcher(id)
        except Exception as e:
            print(e)
            data = 0x03

        return bytearray([data])


    def request_telemetry_data(self, id):
        return bytearray([self.param])
