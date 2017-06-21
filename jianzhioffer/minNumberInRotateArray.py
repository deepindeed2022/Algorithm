# -*- coding:utf-8 -*-
class Solution:
    def minNumberInRotateArray(self, rotateArray):
        if len(rotateArray) == 0: return 0
        i = 0
        j = len(rotateArray) - 1
        mid = (i + j) >> 1
        while i < j and rotateArray[i] >= rotateArray[j]:
        	mid = (i + j) >> 1
        	if rotateArray[mid] > rotateArray[i]:
        		i = mid+1
        	elif rotateArray[mid] < rotateArray[j]:
        		j = mid
        	else:
        		i += 1
        return rotateArray[i]

	def min_number_in_rotate_array(self, rotateArray):
		if len(rotateArray) == 0:
			return 0
		else:
			for i in xrange(len(rotateArray)):
				if rotateArray[i] > rotateArray[i+1]:
					return rotateArray[i+1]
					break
		return 0
def test_minNumberInRotateArray():
	a = [i for i in xrange(10000, 90000)] + [i for i in xrange(1, 10000)]
	solve = Solution()
	print solve.minNumberInRotateArray(a)
	assert 1 == solve.minNumberInRotateArray(a)
	#assert 1 == solve.minNumberInRotateArray([i for i in xrange(1, 6)])
if __name__ == '__main__':
	test_minNumberInRotateArray()