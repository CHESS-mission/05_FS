import socket



def manage_data(data,adcs):
    orbit = data[0]
    adcs.switcher(orbit)

def runTCP(adcs):
    TCP_IP = '127.0.0.1'
    TCP_PORT = 5005
    BUFFER_SIZE = 20

    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    print(f"starting up on {TCP_IP} port {TCP_PORT}")
    s.bind((TCP_IP, TCP_PORT))
    s.listen(1)

    while 1:
        print("Waiting connexion")
        conn, addr = s.accept()
        try:
            print('Connection address:', addr)
            while 1:
                data = conn.recv(BUFFER_SIZE)
                if data:
                    int_data = [i for i in data]
                    print(int_data)
                    manage_data(int_data,adcs)
                    print('sending data back to client')
                    conn.send(data)
                else:
                    print(f"no data from {addr}")
                    break
        finally:
            conn.close()

