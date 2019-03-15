## 问题
Given a string s and a dictionary of words dict, determine if s can be segmented into a space-separated
sequence of one or more dictionary words.
For example, given
s = "leetcode",
dict = ["leet", "code"].
Return true because "leetcode" can be segmented as "leet code".

## 问题
这个问题完全可以使用暴力搜索的方法，对不同长度的substring进行查找所有可能性。但是暴力搜索时间复杂度为O(2^n)
肯定会超时；那么有没有奥德方法进行解决呢

设状态为 f(i)，表示 s[0, i] 是否可以分词，则状态转移方程为
f(i) = any_of(f(j) && s[j + 1; i] \isa dict);  0 ≤ j < i