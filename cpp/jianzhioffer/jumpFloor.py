# -*- coding:utf-8 -*-
class Solution:
    def jumpFloor(self, number):
        # write code here
        if number <= 2:
            return number
        else:
            a = 1
            b = 2
            for i in xrange(1, number):
                a, b = b, a+b
            return a

solve = Solution()
for i in xrange(1, 10):
    print i,":", solve.jumpFloor(i)