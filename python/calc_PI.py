## http://c.biancheng.net/cpp/html/2813.html
t = 0xFFFFFFF
pi = 1.0
for i in xrange(1,t):
	temp = 4*i**2
	pi *= temp/float(temp - 1)
print 2*pi