# -*- coding:utf-8 -*-

class Solution:
    # s 源字符串
    def replaceSpace(self, s):
        # write code here
        s = s.replace(' ', '%20')
        return s

solve = Solution()
s = "hello world"
print solve.replaceSpace(s)
print s
