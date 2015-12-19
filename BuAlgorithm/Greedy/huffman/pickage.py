import struct
import pickle

code_data = '010101010101010111111100000'
# save the compress data into file
f = open('wg.txt', 'wb')
for i in range(0, len(code_data), 8):
    if i + 8 < len(code_data):
        f.write(struct.pack('B', int(code_data[i:i + 8], 2)))
    else:
        # padding
        f.write(struct.pack('B', int(code_data[i:], 2)))
