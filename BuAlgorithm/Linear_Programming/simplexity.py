#-*- encode:utf-8 -*-
# Simplx algorithm for Linner Programming
# date: 2015-11-22
# author: 523814299@qq.com
import sys # use maxint attribute
import logging
lzero = lambda x: x < 0
logging.basicConfig(
    filename='simplex.log',
    level=logging.DEBUG,
    format='%(asctime)s  %(filename)s[line:%(lineno)d] %(levelname)s %(message)s',
    datefmt='%a, %d %b %Y %H:%M:%S',
)
def lmini(l):
	return l.index(min(l))

def simplex(A, b, c):
	"""
	A : a Mutrix for a_ij is coefficient for s.t. equation
	b : Ax = b, b is the mutilt target
	c : linner Programming target coefficients
	"""
	m = len(A)
	if m:
		n = len(A[0])
	else:
		return "too little of s.t."

	def __opt_solution(BI, A, b, c, z):
		delta = [0 for i in range(m)]
		while True :
			if len(filter(lzero , c)) == 0:
				return (BI, A, b, c, z)
			# e for enter basic vector's index
			e = lmini(c)
			for i in range(m):
				if A[i][e] > 0 :
					delta[i] = float(b[i])/A[i][e]
				else:
					delta[i] = sys.maxint

			l = lmini(delta)
			if delta[l] == sys.maxint:
				return "unbounded"
			(BI, A, b, c, z) = pivot(BI, A, b, c, z, e, l);

	def initializeSimplex(A, b, c):
		# the index of minimun b
		l = lmini(b)
		z = 0
		# include the indices of slack variable
		BI = [i for i in range(m,n)]			

		if b[l] >= 0:
			return (BI, A, b, c, z)
		# constuct Laux by adding -x0 to each constraint
		for j in range(m):
			A[j].append(-1)
		# perform one step of pivot to make all bi positive
		(BI, A, b, c, z) = pivot(BI, A, b, c, z, l, 0)
		(BI, A, b, c, z) = __opt_solution(BI, A, b, c, z)
		if z == 0:
			return (BI, A, b, c, z)
		else:
			return ('infeasiable', 'infeasiable','infeasiable', 'infeasiable','infeasiable')



	def calculateX(BI, A, b, c):
		x = [0 for i in range(n)];
		for j in range(n):
			if j not in BI:
				x[j] = 0
			else:
				for i in range(m):
					if A[i][j] == 1:
						x[j] = b[i]
		return x

	def pivot(BI, A, b, c, z, e, l):
		leave = 0
		for i in range(n):
			if i in BI and c[i] == 0:
				leave = i 
				break
		bl = b[l]
		# scaling the l-th line
		b[l] = float(b[l])/float(A[l][e])
		for j in range(n):
			A[l][j] = float(A[l][j])/A[l][e]

		# all the lines minus the l-th line
		for i in range(m):
			if i != l:
				b[i] = b[i] - A[i][e]*b[l]
				aie = A[i][e]
				for j in range(n):
					A[i][j] = A[i][j] - aie*A[l][j]
		# the first line minuses the l-th line		
		ce = c[e]
		z = float(z) - float(b[l]*ce)
		for j in range(n):
			c[j] = float(c[j]) - float(ce*A[l][j])

		try:
			BI.remove(leave)
			BI.append(e)
		except ValueError:
			BI.append(e)

		return (BI, A, b, c, z)
	
	
	(BI, A, b, c, z) = initializeSimplex(A, b, c)
	if z == "infeasiable":
		return ("infeasiable","infeasiable")
	delta = [0 for i in range(m)]
	while True :

		if len(filter(lzero , c)) == 0:
			x = calculateX(BI, A, b, c)
			return (x, z)
	
		# e for enter basic vector's index
		e = 0
		for i in range(n):
			if c[i] < 0 and i not in BI:
				e = i 
				break
		for i in range(m):
			if A[i][e] > 0 :
				delta[i] = float(b[i])/A[i][e]
			else:
				delta[i] = sys.maxint

		l = lmini(delta)
	
		if delta[l] == sys.maxint:
			return "unbounded"

		(BI, A, b, c, z) = pivot(BI, A, b, c, z, e, l);
		
	# end of simplex algorithm
def main():
	A = [[1, 1, 1, 1, 0, 0, 0],
		 [1, 0, 0, 0, 1, 0, 0],
		 [0, 0, 1, 0, 0, 1, 0],
		 [0, 3, 1, 0, 0, 0, 1]]
	b = [4,2,3,6]
	c = [1,-14,-6,0, 0, 0, 0]
	(x, z) = simplex(A, b, c)
	print -z

if __name__ == '__main__':
	main()