class Solution(object):
	def minPatches(self, nums, n):
	    miss = 1
	    added = 0
	    i = 0
	    while miss <= n:
	        if i < len(nums)  and nums[i] <= miss:
	            miss += nums[i]
	            i += 1
	        else:
	            miss += miss
	            added += 1
	    return added



S = Solution()

nums = [1,3]
n = 6
print S.minPatches(nums, n)

nums = [1,5,10]
n = 20
print S.minPatches(nums, n)

# class Solution(object):
# 	def minPatches(self, nums, n):
# 	    """
# 	    :type nums: List[int]
# 	    :type n: int
# 	    :rtype: int
# 	    """
# 	    count = 0
# 	    s = 0
# 	    for x in nums:
# 	        if s >= n:
# 	            return count
# 	        while s < x-1:  # x-1 is the goal; when reaches the goal, we can represent [1, x)
	            
# 	            s += s + 1  # add a resource number
# 	            count += 1
# 	            if s >= n:
# 	                return count
# 	        s += x
# 	    while s + 1 <= n:
# 	        count += 1
# 	        #sum += sum + 1
# 	    return count