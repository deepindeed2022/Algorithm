#!encode=utf-8
"""Note:
the computer save negative number using code
"""
def getSum(a, b):
	"""
	:type a: int
	:type b: int
	:rtype: int
	"""
	MAX_INT = 0x7FFFFFFF
	MIN_INT = 0x80000000
	MASK 	= 0x100000000
	while b:
	    a, b = (a ^ b) % MASK, ((a & b) << 1) % MASK
	#print (a % MIN_INT) ^ MAX_INT

	return a if a <= MAX_INT else ~((a % MIN_INT) ^ MAX_INT)


print getSum(-1, -9)
print getSum(3, -5)
print getSum(3, 4)
