# -*- coding:utf-8 -*-
class Solution:
    def Power(self, base, exponent):
        # write code here
        if exponent < 0:
        	return 1.0/(float)(self.Power(base, -exponent))
        elif exponent == 0:
        	return 1
        elif exponent % 2 == 0:
        	return self.Power(base, exponent/2)**2
        else:
        	return base * self.Power(base, exponent/2)**2

solve = Solution()

print solve.Power(1.5, 2)
print solve.Power(1.5, -1)
print solve.Power(1.2, 0)
print solve.Power(1.2, 3)
