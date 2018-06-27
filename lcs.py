
# def lcs(a, b):
# 	la = len(a)
# 	lb = len(b)
# 	c = [[0 for i in range(lb+1)] for j in range(la+1)]
# 	flag = [[0 for i in range(lb+1)] for j in range(la+1)]
# 	for i in range(la):
# 		for j in range(lb):
# 			if a[i] == b[j]:
# 				c[i+1][j+1] = c[i][j] + 1
# 				flag[i+1][j+1] = 'ok'
# 			elif c[i+1][j] > c[i][j+1]:
# 				c[i+1][j+1] = c[i+1][j]
# 				flag[i+1][j+1] = 'left'
# 			elif c[i][j+1] > c[i+1][j]:
# 				c[i+1][j+1] = c[i][j+1]
# 				flag[i+1][j+1] = 'up'
# 	return c, flag

def lcs(a, b):
	la = len(a)
	lb = len(b)
	c = [[0 for i in range(lb+1)] for j in range(la+1)]
	for i in range(la):
		for j in range(lb):
			if a[i] == b[j]:
				c[i+1][j+1] = c[i][j] + 1
			else:
				c[i+1][j+1] = max(c[i+1][j],c[i][j+1])

	return c[la][lb]

def main(s):
    b = s[::-1]
    print(len(s) - lcs(s, b))
    
if __name__ == '__main__':
    a_1 = "abcdcba"
    a_2 = "dcba"
    print lcs(a_1, a_2)
    # while(1):
        # s = raw_input()
		# main(raw_input())