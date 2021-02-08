class Uart:
    CRC_POLY = 0x91
    CRC8Table = [0] * 256

    for i in range(256):
        val = i
        for j in range(8):
            if val & 1:
                val ^= CRC_POLY
            val >>= 1
        CRC8Table[i] = val

    def __init__(self,id):
        self.id=id
        self.create_return_packet()

    def create_return_packet(self) -> bytearray:
        self.packet = bytearray([0x1F, 0x7F, self.id])

    def end_packet(self,data):
        self.packet.append(data)
        return self.packet + bytearray([0x1F, 0xFF])

    @classmethod
    def checksum(cls,array):
        crc = 0
        for b in array:
            crc = cls.CRC8Table[crc ^ b]
        return crc

    @classmethod
    def check_packet(cls,packet:bytearray) -> int:
        code = 0x00
        if packet[0] == 0x1F and packet[1] == 0x7F:
            if packet[-2] == 0x1F and packet[-1] == 0xFF:
                if packet[2] < 128:
                    print('Telecommand packet')
                    if cls.checksum(packet[2:-3]) == packet[-3]:
                        print("Telecommand packet OK")
                    else:
                        print("CRC error")
                        code = 0x04
                else:
                    print('Telemetry packet')
                    if len(packet) == 5:
                        print("Telemetry packet OK")
                    else:
                        print("error in  Telemetry packet length")
                        code = 0x02
            else:
                print("error in end message or Data byte bytes")
                code = 0x02
        else:
            print("error in Start message or Data byte bytes")
            code = 0x02

        return code

    @staticmethod
    def get_id(packet):
        return packet[2]

    @staticmethod
    def get_data(packet):
        return packet[3:-3]
