# This is a sample Python script.

# Press Maj+F10 to execute it or replace it with your code.
# Press Double Shift to search everywhere for classes, files, tool windows, actions, and settings.
from packages.state_machine.StateMachine import ADCSStateMachine
from packages.tcp.TcpServer import runTCP



# Press the green button in the gutter to run the script.
if __name__ == '__main__':
    adcs = ADCSStateMachine()
    print("state machine build")
    print(adcs.current_state)
    print(f"adcs parameter : {adcs.param}")
    print("create connexion")
    runTCP(adcs)



# See PyCharm help at https://www.jetbrains.com/help/pycharm/
