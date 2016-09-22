#include <assert.h>
#include <iostream>
#include <string>
using std::cout;
using std::string;

class Solution 
{
public:
    // Decide the char is vowel or not,
    bool isVowel(char c)
    {
        return c=='a' || c=='e' || c=='i' || c=='o' || c=='u'
            || c=='A' || c=='E' || c=='I' || c=='O' || c=='U';
    }

    string reverseVowels(string s) 
    {
        int i=0, j=s.size()-1;
        while(1)
        {
            while(i < j && !isVowel(s[i]))
                i++;
            while(i < j && !isVowel(s[j]))
                j--;

            if(i >= j) break;

            std::swap(s[i++], s[j--]);
        }

        return s;
    }
};

///////////////////////////////////////////
//
// TEST_CODE MAIN FUNCTION TO CALL
//
///////////////////////////////////////////

int main(int argc, char const *argv[])
{
  Solution solve;
  string s("hello");
  std::cout << "START TEST:\n";
  assert("holle" == solve.reverseVowels(s));
  assert("niice" == solve.reverseVowels("neici"));
  std::cout << "TEST SUCCESS!\n";
  return 0;
}