# -*- coding:utf-8 -*-
import math
class Solution:
    def jumpFloorII(self, number):
        if number <= 1:
        	return 1
        else:
        	return math.pow(2, number - 1)

solve = Solution()
for i in xrange(1, 10):
	print solve.jumpFloorII(i)