def fibonacci(n):
	fib = {1:1,2:1}
	if n in fib.keys():
		return fib[n]
	else:
		fib[n] = fibonacci(n-1) + fibonacci(n-2)
		return fib[n]
def fib(n):
    a = 1
    b = 1
    for i in xrange(1, n):
        a, b = b, a+b
    return a
if __name__ == '__main__':
	print fib(5)
	print fib(6)
