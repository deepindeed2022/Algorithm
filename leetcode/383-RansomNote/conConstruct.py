import collections
class Solution(object):
    def canConstruct(self, ransomNote, magazine):
        """
        :type ransomNote: str
        :type magazine: str
        :rtype: bool
        """
        return not collections.Counter(ransomNote) - collections.Counter(magazine)

def test_canConstruct():
    solve = Solution()
    assert solve.canConstruct("aa", "ab") == False
    assert solve.canConstruct("abab", "abababababa") == True
    
if __name__ == '__main__':
    test_canConstruct()