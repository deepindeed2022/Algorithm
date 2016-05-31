class Solution(object):
    # def permute(self, nums):
	   #  ans = [[]]   
	   #  for n in nums:
	   #      new_perms = []
	   #      for perm in ans:
	   #          for i in xrange(len(perm)+1):   
	   #              new_perms.append(perm[:i] + [n] + perm[i:])   ###insert n
	   #      ans = new_perms
	   #  return ans
	def permute(self, nums):
		return nums and [p[:i] + [nums[0]] + p[i:]
                     for p in self.permute(nums[1:])
                     for i in range(len(nums))] or [[]]
S = Solution()
nums = [1,2,3]
print S.permute(nums)
