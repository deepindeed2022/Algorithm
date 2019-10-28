class Solution(object):
    def reverseWords(self, s):
        """
        :type s: str
        :rtype: str
        """
        return " ".join(map(lambda x: x[::-1], s.split()))

if __name__ == '__main__':
	s = Solution()
	print(s.reverseWords("Let's take LeetCode contest"))