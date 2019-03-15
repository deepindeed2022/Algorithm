# -*- coding:utf-8 -*-
class Solution:
    def rectCover(self, number):
        # write code here
       	if number <= 2:
       		return number
       	else:
       		a = 1
       		b = 2
       		for i in xrange(number -1):
       			a, b = b, a + b
       		return a

solve = Solution()
for i in xrange(1, 10):
	print "%d:%d" % (i, solve.rectCover(i))