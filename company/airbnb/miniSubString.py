"""
Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

Example:

Input: S = "ADOBECODEBANC", T = "ABC"
Output: "BANC"
Note:

If there is no such window in S that covers all characters in T, return the empty string "".
If there is such window, you are guaranteed that there will always be only one unique minimum window in S.
"""

from collections import Counter

def minimumSubstring(s, alphabet):
    need, missing = Counter(alphabet), len(alphabet)
    print need, missing
    i = start = end = 0
    # moving the right point to find all the need characters
    for j, c in enumerate(s, 1):
        # print j, c
        missing -= (need[c] > 0)
        need[c] -= 1
        if not missing:
            # move the left point, the left character add into need array
            while i < j and need[s[i]] < 0:
                need[s[i]] += 1
                i += 1
                print need
            # use the smaller interval [i, j] instead of origin [start, end]
            if not end or j - i <= end - start:
                start, end = i, j
                #print start, end
    return s[start:end]


s = "ADOBECODEBANC"
t = "ABC"
print minimumSubstring(s, t)

