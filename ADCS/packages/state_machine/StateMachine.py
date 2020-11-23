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
            if val & 1 :
                val ^=CRC_POLY
            val >>= 1
        CRC8Table[i] = val

    def __str__(self):
        return f"{self.current_state} set, param = {self.param}"

    @staticmethod
    def checksum(array):
        crc = 0
        for b in array:
            crc = ADCSStateMachine.CRC8Table[crc ^ b]
        return crc

    def switcher(self, case):
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

    def on_enter_low_orbit(self):
        self.param = 10
        print(f"{self.current_state} set, param = {self.param}")

    def on_enter_middle_orbit(self):
        self.param = 20
        print(f"{self.current_state} set, param = {self.param}")

    def on_enter_high_orbit(self):
        self.param = 30
        print(f"{self.current_state} set, param = {self.param}")


