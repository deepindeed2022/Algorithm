def fibonacci(n):
	fib = {1:1,2:1}
	if n in fib.keys():
		return fib[n]
	else:
		fib[n] = fibonacci(n-1) + fibonacci(n-2)
		return fib[n]

if __name__ == '__main__':
	print fibonacci(5)
	print fibonacci(6)
