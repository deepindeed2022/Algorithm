# using huffman code and decompress a file
from collections import Counter
import logging

logging.basicConfig(
    filename='huffman.log',
    level=logging.DEBUG,
    format='%(asctime)s  %(filename)s[line:%(lineno)d] %(levelname)s %(message)s',
    datefmt='%a, %d %b %Y %H:%M:%S',
)


def read_from_file(filename = "Aesop_Fables.txt"):
	f = open(filename)
	c = Counter(f.read())
	return c

def count_probability(counter = Counter()):
	pass

def construct_huffman_tree():
	pass

def compress_file():
	pass
	
def decompress_file(file, huffman_tree):
	pass

if __name__ == '__main__':
	fname = "Aesop_Fables.txt"
	print read_from_file(fname)
