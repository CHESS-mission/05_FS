from statemachine import StateMachine, State


class EPSStateMachine(StateMachine):
    working = State('working')
    default = State('Default', initial=True)
    ground = State('Ground')
    factory = State('Factory')

    working_to_default = working.to(default)
    working_to_ground = working.to(ground)
    working_to_factory = working.to(factory)

    default_to_working = default.to(working)
    default_to_ground = default.to(ground)
    default_to_factory = default.to(factory)

    ground_to_default = ground.to(default)
    ground_to_working = ground.to(working)
    ground_to_factory = ground.to(factory)

    factory_to_default = factory.to(default)
    factory_to_ground = factory.to(ground)
    factory_to_factory = factory.to(working)


    volt = 10
    temp = 50
    mode = 2


    def __str__(self):
        return f"{self.current_state} set, volt = {self.volt}"

    def request(self, data:bytearray):
        self.volt = 10 if self.volt == 11 else 11
        back_data = bytearray(232)
        back_data[0] = data[0]
        back_data[1] = 0
        back_data[26] = self.volt
        back_data[206] = self.temp
        back_data[226] = self.mode
        return back_data


