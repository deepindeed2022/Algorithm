from collections import Counter
def minimumSubstring(s, alphabet):
    need, missing = Counter(alphabet), len(alphabet)
    i = start = end = 0
    # moving the right point to find all the need characters
    for j, c in enumerate(s, 1):
        # print j, c
        missing -= (need[c] > 0)
        need[c] -= 1
        if not missing:
            # move the left point
            while i < j and need[s[i]] < 0:
                need[s[i]] += 1
                i += 1
                # print need
                # print s[i]
            if not end or j - i <= end - start:
                start, end = i, j
                print start, end
    return s[start:end]

s = "ADOBECODEBANC"
t = "ABC"
print minimumSubstring(s, t)