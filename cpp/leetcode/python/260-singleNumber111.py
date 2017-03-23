# Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once.
#
# For example:
# Given nums = [1, 2, 1, 3, 2, 5], return [3, 5].
#
# Note:
# The order of the result is not important. So in the above example, [5, 3] is also correct.
# Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?

class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        val = 0
        for n in nums: val ^= n

        mask = 1
        while val&mask == 0: mask <<=1
        a, b = 0, 0
        for n in nums: 
        	if n & mask: 
        		a^=n 
    		else: 
    			b^=n
        return [a, b] 

def test_solution():
	solver = Solution()
	nums = [1, 2, 1, 3, 2, 5]
	assert 3 in solver.singleNumber(nums)
	assert 5 in solver.singleNumber(nums)
	assert 2 == len(solver.singleNumber(nums))
if __name__ == '__main__':
	test_solution()

	