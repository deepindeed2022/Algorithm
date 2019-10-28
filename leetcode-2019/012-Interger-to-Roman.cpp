#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    string intToRoman(int num) 
    {
        int x[]   ={ 1,    4,  5,   9, 10,  40, 50, 90, 100, 400,500, 900,1000};
        string s[]={"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
        
        string ans="";
        for(int i=12;i>=0;i--) {
            while(num>=x[i]) {
               ans=ans+s[i]; 
               num=num-x[i];
            }    
        }
        
        return ans;
    }
};
int main(int argc, char const *argv[])
{
    Solution s;
    std::cout << s.intToRoman(58) << std::endl;
    std::cout << s.intToRoman(1994) << std::endl;
    return 0;
}