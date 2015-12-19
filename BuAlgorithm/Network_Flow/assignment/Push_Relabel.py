import sys

def push_relabel(Graph, s, t):
	def push(Graph, e, f, u, v):
		'''
		push water from u to v 
		'''
		df = min(e[u], Graph[u][v] - f[u][v])
		f[u][v] = f[u][v] + df
		f[v][u] = -f[u][v]
		e[u] = e[u] - df
		e[v] = e[v] + df

	def relabel(Graph, f, u):
		minh = 2 * num - 1
		for i in range(num):
			if Graph[u][i] > abs(f[u][i]) and h[u] <= h[i] and h[i] < minh: 
				minh = h[i]
		h[u] = 1 + minh

	def init_preflow(Graph, s):
		num = len(Graph)

		h = [0 for i in range(num)]
		e = h[:]
		f = [[0 for i in range(num)] for j in range(num)]
	   	h[s] = num

	   	for j in range(num):
	   		f[s][j] = Graph[s][j]
	   		
			if Graph[s][j] != 0:
				e[j] = Graph[s][j]
				e[s] = e[s] - Graph[s][j]

		return (f,h,e)

	num = len(Graph)
	(f, h, e) = init_preflow(Graph, s)

	while True:
		flag = False
		for i in range(num):
			if e[i] > 0 and i not in [s, t]:
				for j in range(num):
					if Graph[i][j] > f[i][j]  and h[i] > h[j]:
						push(Graph, e, f, i, j)
						flag = True
				if flag == False:
					for j in range(num):
						if Graph[i][j] > f[i][j] and h[i] <= h[j]:
							relabel(Graph, f, i)
							flag = True
							break
		if flag == False:
			break
		return (abs(e[s]), f)
	
def find_matrix_matching(filename):
	with open(filename, 'r') as f:
		line = f.readline()
		while line:
			if line.startswith('#'):
				pass
			else:
				M, N = line.strip().split(' ', 1)

				M, N = int(M), int(N) 
				row = f.readline()
				column = f.readline()
				row = map(lambda x:int(x), row.strip().split())
				column = map(lambda x:int(x), column.strip().split())
				Graph = [[0 for i in range(M+N+2)] for j in range(M+N+2)]
				# init source
				for i in range(M): Graph[M + N][i] = row[i]

				for i in range(M): 
					for j in range(N): Graph[i][M + j] = 1
				# init tink vertice
				for j in range(N): Graph[M+j][M+N+1] = column[j]

				# Calculate the max flow of Graph
				flow, ff = push_relabel(Graph, M + N , M+N+1)
				print "the max flow: ",flow, " the matrix exist:", flow == sum(row)
			# read the next graph
			line = f.readline()


def main():
	filename = 'problem2.data'
	find_matrix_matching(filename)
	
if __name__ == '__main__':
	main()
