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


    def __str__(self):
        return f"{self.current_state} set, volt = {self.volt}"

    def request_cmd(self, data:bytearray):
        print(data)
        return bytearray([10,12,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1])


