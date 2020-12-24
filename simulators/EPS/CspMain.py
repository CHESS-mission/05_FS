# This is a sample Python script.

# Press Maj+F10 to execute it or replace it with your code.
# Press Double Shift to search everywhere for classes, files, tool windows, actions, and settings.
import packages.csp.CspServer as cspServer
from packages.state_machine.StateMachine import EPSStateMachine


# Press the green button in the gutter to run the script.
if __name__ == '__main__':
    eps = EPSStateMachine()
    print("state machine build")
    print(eps.current_state)
    print(f"eps volt : {eps.volt}")
    print("create connexion")
    cspServer.init(eps)



# See PyCharm help at https://www.jetbrains.com/help/pycharm/
