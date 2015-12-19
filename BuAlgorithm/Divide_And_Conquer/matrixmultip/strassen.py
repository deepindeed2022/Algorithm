# -* -utf-8 -*--
def getdata_from_file(filename = "multip.txt"):
	result = []
	with open(filename) as f:
		for line in f:
			lines = line.strip().split(' ')
			result.append(map(int,filter(lambda x : x.isdigit(), lines)))

	A = result[1 : int(result[0][0]) + 1]
	B = result[len(A) +2: len(A) + 2 + int(result[len(A)+1][0])]

	return A, B


def grade_school(A, B):
	return multip_matrix(A, B)

def multip_matrix(A, B):
	if not A and B:
		raise TypeError("matrix size invalid") 

	l = len(A)
	m = len(B)
	if len(A[0]) != m:
		raise TypeError("matrix size invalid") 
	r = len(B[0])

	C = [ [ 0 for j in range(r)] for i in range(l)]
	for i in range(l):
		for j in range(r):
			for k in range(m):
				C[i][j]+=A[i][k]*B[k][j]

	return C

def add_matrix(A, B):
	l, r = len(A), len(B[0])
	#if len(B[0]) != r or len(B) != l or not A:
	#	raise TypeError("Matrix size invalid") 
	return [ [A[i][j]+B[i][j] for j in range(r)] for i in range(l)]

def dec_matrix(A, B):
	l, r = len(A), len(A[0])
	#if len(B[0]) != r or len(B) != l or not A:
	#	raise TypeError("Matrix size invalid") 
	return [ [A[i][j]-B[i][j] for j in range(r)] for i in range(l)]
def print_m(A):
	for i in A:
		for j in i:
			print j,
		print 	

def divide_matrix(A):
	l = len(A)
	r = len(A[0])
	l1, r1 = l/2, r/2
	U, D = A[0:l1], A[l1:]
	A1, A2 = [[i[j] for j in range(r1)] for i in U],[[i[j] for j in range(r1,l)] for i in U]
	A3, A4 = [[i[j] for j in range(r1)] for i in D],[[i[j] for j in range(r1,l)] for i in D]
	return A1, A2, A3, A4 

def merger_matrix(A11, A12, A21, A22):
	l = len(A11)
	C = [[] for i in range(2*l)]
	B11, B12, B21, B22 = A11, A12, A21, A22
	i = 0
	while i < l:
		B11[i].extend(B12[i])
		C[i] = B11[i]

		B21[i].extend(B22[i])
		C[i+l] = B21[i]
		i += 1
	return C
def strassen(A, B):
	if len(A) <= 40:
		return multip_matrix(A, B)
	# divide the matrix 
	A11, A12, A21, A22 = divide_matrix(A)
	B11, B12, B21, B22 = divide_matrix(B)
	
	M1 = strassen(A11, dec_matrix(B12,B22))
	M2 = strassen(add_matrix(A11, A12), B22)
	M3 = strassen(add_matrix(A21, A22), B11)
	M4 = strassen(A22, dec_matrix(B21,B11))

	M5 = strassen(add_matrix(A11, A22), add_matrix(B11, B22))
	M6 = strassen(dec_matrix(A12, A22), add_matrix(B21, B22))
	M7 = strassen(dec_matrix(A11, A21), add_matrix(B11, B12))
	# strassen addition
	C11 = add_matrix(dec_matrix(add_matrix(M5,M4),M2),M6)
	C12 = add_matrix(M1, M2)
	C21 = add_matrix(M3, M4)
	C22 = dec_matrix(dec_matrix(add_matrix(M5,M1),M3),M7)
	#
	return merger_matrix(C11,C12,C21,C22)

import time
if __name__ == '__main__':
	for i in ["multip.txt","multip_20.txt","multip_60.txt","multip_160.txt","multip_320.txt"]:
		A, B = getdata_from_file(i)

		#print dec_matrix(A, B)
		#print merger_matrix(A, A, A, A)
		test_time = 10
		start = time.clock()
		for i in range(test_time):
			multip_matrix(A, B)
		middle = time.clock()
		for i in range(test_time):
			strassen(A, B)
		end = time.clock()

		print "multip_matrix average running time: %f s, strassen  average running time: \
				%f s" %((middle-start)/test_time, (end- middle)/test_time)
		
	