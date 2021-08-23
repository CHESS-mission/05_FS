from statemachine import StateMachine, State
from packages.package.UART import Uart

listTC = {
    1:"reset",
    4:"reset log pointer",
    5:"advance log pointer",
    6:"reset boot registers",
    108:"erase file",
    112:"load file donwload block",
    113:"advance file list read pointer",
    114:"initiate file upload",
    115:"file upload packet",
    116:"finalize upload block",
    117:"reset upload block",
    118:"reset file list read pointer",
    119:"initate donwload burst"
}

listTM = {

}

class ADCSStateMachine(StateMachine):
    low_orbit = State('Low orbit', initial=True)
    middle_orbit = State('Middle orbit')
    high_orbit = State('High orbit')

    up_middle = low_orbit.to(middle_orbit)
    up_high = middle_orbit.to(high_orbit)
    down_middle = high_orbit.to(middle_orbit)
    down_low = middle_orbit.to(low_orbit)

    param = 10


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

    def exec_command(self, id):
        try:
            print(listTC[id])
            data = self.switcher(id)
        except Exception as e:
            print(e)
            data = 0x03

        return data

    def request_telemetry_data(self, id):
        return self.param

    def request(self,packet:bytearray) -> bytearray:
        code = Uart.check_packet(packet)            #error code (?)
        id = Uart.get_id(packet)                    #third byte on the received data
        uart_packet = Uart(id)
        if code == 0:                               #if no errors in received data
           if id < 128:                             #telecomand
                code = self.exec_command(id)
                return uart_packet.end_packet(code)
           else:                                    #telemetry
                tm = self.request_telemetry_data(id)
                return uart_packet.end_packet(tm)
        else:
            return Uart(id).end_packet(code)
