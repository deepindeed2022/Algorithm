#!/usr/bin/python 
# -*- coding: utf-8 -*- 

"""
【第四题】最小差值
输入一个整数数组a，和一个整数k，对于a中每一个元素，必须进行一次操作（加上k或者减去k），要求是数组中所有元素执行完操作后，整个数组最大和最小值之差最小。
输出这个差值。
例如
输入：数组a为：[1, 7, 3, 5]，k为3
输出：4
"""

def mini_op_price(arr, k):
	size = len(arr)
	avg = sum(arr)/float(size)
	for i in xrange(size):
		if arr[i] < avg:
			arr[i] += k
		else:
			arr[i] -= k
	return max(arr) - min(arr)


if __name__ == '__main__':
	a = [1, 7, 3, 5]
	k = 3
	print mini_op_price(a, k)