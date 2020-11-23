import socket
from packages.state_machine.StateMachine import ADCSStateMachine

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server_address = ('localhost', 5005)

if __name__ == '__main__':
    s.connect(server_address)

    try:
        message = bytearray([1,2,3,4,5])
        message.append(ADCSStateMachine.checksum(message))
        print(message)
        s.send(message)

        amount_received = 0
        amount_expected = len(message)

        while amount_received < amount_expected :
            data = s.recv(20)
            amount_received += len(data)
            print(f"received {data}")
    finally:
        print("close socket")
        s.close()