import struct

def get_key():
    target_bytes = 'This'.encode('utf8')

    key = bytearray([0x00, 0x00, 0x00, 0x00])
    i = 0

    with open('mfc100.dll.encrypted', 'rb') as f:
        f.seek(0x40, 0)
        input_bytes = f.read(4)[:len(key)]
        for i in range(len(key)):
            for j in range(0, 0xFF + 1):
                if input_bytes[i] ^ j == target_bytes[i]:
                    key[i] = j
                    break

    return key.decode('utf8')

def decode_file(key: str):
    if len(key) < 1:
        return

    with open('mfc100.dll.encrypted', 'rb') as f_enc, open('mfc100.dll', 'wb') as f:
        i = 0
        byte = f_enc.read(1)
        while byte != b'':
            f.write(struct.pack('B', byte[0] ^ ord(key[i % len(key)])))
            byte = f_enc.read(1)
            i += 1

decode_file(get_key())