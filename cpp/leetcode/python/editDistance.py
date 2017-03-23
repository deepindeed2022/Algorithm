#!/usr/bin/python 
# -*- coding: utf-8 -*- 
# Given two words word1 and word2, find the minimum number of steps required to convert word1 to
# word2. (each operation is counted as 1 step.)
# You have the following 3 operations permied on a word:
# • Insert a character
# • Delete a character
# • Replace a characte

def minDistance(word1, word2):
	'''由于我们在DP过程中仅仅是对上一行的数据操作获得下一行的数据，
	我们完全可以考虑将不重用的数据空间提前释放或者申请适量的数据空间
	而不是申请一个二维数组空间进行存储数据
	'''
	if(len(word1) < len(word2)):
		return minDistance(word2, word1)
	l = len(word1)
	
	# 初始化动态规划数组空间，相当于对于word2 == 0的时候，对于word1不同位置
	# 的时候对应的编辑距离， 因此，结果应该存储在f[l]的位置
	f = [i for i in range(l+1)]
	
	# DP获取最小编辑距离
	for i in range(1, l+1):
		upper_left = f[0] # save the f[i-1][j-1]
		f[0] = i
		for j in range(1, l+1):
			upper = f[j]
			if word1[i-1] == word2[j-1]:
				f[j] = upper_left
			else:
				f[j] = 1 + min(upper_left, min(f[j], f[j-1]))
			upper_left = upper
	return f[l]

def test_minDistance():
	word1 = "hjllo"
	word2 = "hello"
	assert minDistance(word1, word2) == 1

if __name__ == '__main__':
	test_minDistance()
			