// Given a string, find the length of the longest substring without repeating 
// characters.
//
// Examples:
// Given "abcabcbb", the answer is "abc", which the length is 3.
// Given "bbbbb", the answer is "b", with the length of 1.
// Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer 
// must be a substring, "pwke" is a subsequence and not a substring.

/**
 * Solution (DP, O(n)):
 * 
 * Assume L[i] = s[m...i], denotes the longest substring without repeating
 * characters that ends up at s[i], and we keep a hashmap for every
 * characters between m ... i, while storing <character, index> in the
 * hashmap.
 * We know that each character will appear only once.
 * Then to find s[i+1]:
 * 1) if s[i+1] does not appear in hashmap
 *    we can just add s[i+1] to hash map. and L[i+1] = s[m...i+1]
 * 2) if s[i+1] exists in hashmap, and the hashmap value (the index) is k
 *    let m = max(m, k), then L[i+1] = s[m...i+1], we also need to update
 *    entry in hashmap to mark the latest occurency of s[i+1].
 * 
 * Since we scan the string for only once, and the 'm' will also move from
 * beginning to end for at most once. Overall complexity is O(n).
 *
 * If characters are all in ASCII, we could use array to mimic hashmap.
 **/
 
 #include <string>
 #include <vector>
 #include <iostream>
 using namespace std;
 #include <cassert>
 
int lengthOfLongestSubstring(string s) {
    std::vector<int> chhash(256, -1);
    int length = 0, m = 0;
    for(int i = 0; i < s.size(); ++i)
    {
        m = max(chhash[s[i]] + 1, m);
        chhash[s[i]] = i;
        length = max(length, i - m + 1);
    }
    return length;
}
int main(int argc, char const *argv[])
{
    assert( 3 == lengthOfLongestSubstring("abcabcbb"));
    assert( 1 == lengthOfLongestSubstring("bbbbb"));
    assert( 3 == lengthOfLongestSubstring("pwwkew"));
    return 0;
}