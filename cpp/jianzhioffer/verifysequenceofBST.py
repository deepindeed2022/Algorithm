# -*- coding:utf-8 -*-
class Solution:
    def verfiy(self, sequence):
        if len(sequence) <= 1: return True
        lastvalue = sequence[-1]
        interval = -1
        for i in xrange(len(sequence)-1):
        	if sequence[i] > lastvalue:
        		interval = i
        		break
        left = sequence[:interval]
        right = sequence[interval:-1]
        if all([x > lastvalue for x in right]):
        	return self.verfiy(left) and self.verfiy(right)
        else:
            return False
    def VerifySquenceOfBST(self, sequence):
        if len(sequence) == 0: return False
        return self.verfiy(sequence)

a = [4,6,7,5]
solve = Solution()
print solve.VerifySquenceOfBST(a)