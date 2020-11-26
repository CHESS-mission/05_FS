import socket
from packages.package.UART import Uart

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server_address = ('localhost', 5005)

messages = [bytearray([0x1F,0x7F,0x80,0x1F,0xFF]),bytearray([0x1F,0x7F,0x00,0x1F,0xFF]),bytearray([0x1F,0x7F,0x80,0x1F,0xFF])]

if __name__ == '__main__':
    s.connect(server_address)
    try:
        for message in messages:

                if message[2] < 128:
                    message.append(Uart.checksum(message))
                    print(f"Sending Telecommand message : command id {message[2]}")
                else:
                    print(f"Sending Telemetry message : Telemetry id {message[2]}")
                s.send(message)

                amount_received = 0
                amount_expected = len(message)

                while amount_received < amount_expected :
                    data = s.recv(4096)
                    amount_received += len(data)
                    print(f"received {data}")
                    if data[2] < 128:
                        print(f"Received Telecommand acknowledge : code {data[3]} \n")
                    else:
                        print(f"Received Telemetry reply : data {data[3]} \n")
    finally:
            print("close socket")
            s.close()