
def getdata_from_file(filename = "Q5.txt"):
	'''Get the raw data from a text file ,default name is Q5.txt,
		where contains 100,000 integers between 1 and 100,000 (each row has a single
		integer), the order of these integers is random and no integer is repeated
	'''
	result = []
	with open(filename) as f:
		for line in f:
			result.append(int(line))
	return result


def sort_and_count(L):
	n = len(L)
	if n == 1:
		return (0, L)
	else:
		A, B = L[0:n/2], L[n/2:]
		(N1, A) = sort_and_count(A)
		(N2, B) = sort_and_count(B)
		(N3, L) = merge_and_count(A, B)
		result = N1 + N2 + N3
		return (result, L)

def merge_and_count(A, B):
	i, j1, j2 = 0, 0, 0 #  i and j2 is to iterate A and B, j1 is to B[j1..j2-1]<A[i]
	inversionCount = 0
	L = []
	while i < len(A) and j2 < len(B):
		if A[i] < B[j2]:
			if A[i] > 3*B[j1]:
				inversionCount += len(A) + j1 - i
				j1+=1
			else:
				L.append(A[i])
				i+=1
		else:
			L.append(B[j2])
			j2+=1

	if j2 < len(B):
		L.extend(B[j2:])

	while i < len(A):
		if j1 < len(B):
			if A[i] > 3*B[j1]:
				inversionCount += len(A) + j1 - i 
				j1 += 1 
			else:
				L.append(A[i])
				i+=1
		else:
			L.append(A[i])
			i+=1
	return (inversionCount, L)


if __name__ == '__main__':
	data = getdata_from_file()
	print sort_and_count(data)[0]

