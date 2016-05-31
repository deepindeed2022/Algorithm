def insertSort(A):
	n = len(A)
	for i in range(n):
		key = A[i]
		j = i - 1
		while j >= 0 and A[j] > key:
			A[j+1] = A[j]
			j -= 1
		A[j+1] = key
	return A
if __name__ == '__main__':
	A = [1, 2, 4, 2, 222, 23, 35, 67]
	print insertSort(A)