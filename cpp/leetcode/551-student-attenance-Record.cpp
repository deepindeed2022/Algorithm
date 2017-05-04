#include <string>

class Solution {
 public:
   bool checkRecord(string s) {
      int len = s.length();
      int a_count = 0;
      for (int i = 0; i < len; i++) {
         if (s[i] == 'A')
            a_count++;
         if (a_count > 1)
            return false;
         if (i < len - 1 && i > 0) {
            if (s[i] == s[i - 1] && s[i] == s[i + 1] && s[i] == 'L')
               return false;
         }
      }
      return true;
   }
};