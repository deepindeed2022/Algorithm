# Given an integer, return its base 7 string representation.

# Example 1:
# Input: 100
# Output: "202"
# Example 2:
# Input: -7
# Output: "-10"
# Note: The input will be in range of [-1e7, 1e7].


class Solution(object):

    def convertToBase7(self, num):
        """
        :type num: int
        :rtype: str
        """
        if num < 0:
            return '-' + self.convertToBase7(-num)
        elif num < 7:
            return str(num)
        else:
            return self.convertToBase7(num / 7) + self.convertToBase7(num % 7)

    def convertToBase7_norecursion(self, num):
        if num < 0:
            return '-' + self.convertToBase7_norecursion(-num)
        else:
            result, res = '', num % 7
            while num / 7 > 0:
                result = str(res) + result
                num = num / 7
                res = num % 7
            return str(res) + result


def test_solution():
    solver = Solution()
    assert solver.convertToBase7(0) == '0'
    assert solver.convertToBase7(7) == '10'
    assert solver.convertToBase7(-7) == '-10'

    assert solver.convertToBase7_norecursion(-7) == '-10'
    assert solver.convertToBase7_norecursion(8) == '11'
    assert solver.convertToBase7_norecursion(-1) == '-1'
if __name__ == '__main__':
    test_solution()
