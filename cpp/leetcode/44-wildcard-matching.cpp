#include <iostream>
#include <string>
#include <cassert>
using namespace std;
string preparepatten(std::string p)
{
    if(p.size() < 3) return p;
    for(int i = 1; i < p.size() - 1; ++i)
    {
        if(p[i -1] == p[i +1] && p[i] == '*')
        {
            p.erase(i);
            --i;
        }
    }
}
bool isMatch(std::string s, std::string p)
{
    int j = 0;
    std::string patten =  preparepatten(p);

    for(int i = 0; i  < s.size(); i++)
    {
        if(j == p.size()) return false;

        char cs = s[i];
        char cp = patten[j];
        //std::cout << cs << " " << cp << std::endl;
        if(cp =='*')
        {
            if(j < patten.size() -1)
            {
                int ii = i;
                while(ii < s.size() && s[ii] != patten[j+1]) ++ii;
                if(ii == s.size()) 
                    return false;
                else if(ii == i)
                {
                    ++j;
                }
                else
                {
                    ++j; 
                    i = ii - 1;
                    continue;
                }
            }
            else
                return true;
        }
        else if(cp == '?')
        {
            j++;
        }
        else
        {
            if(cp != cs) return false;
            ++j;
        }
    }
    if(j < s.size())
    return true;

}

void test_ismatch()
{
    // assert(isMatch("aa", "a") == false);
    // assert(isMatch("aa", "aa"));
    // assert(isMatch("aaa", "a") == false);
    // assert(isMatch("aa", "a*"));
    // assert(isMatch("aa", "*") );
    assert(isMatch("aab", "c*a*b") == false);
}
int main(int argc, char const *argv[])
{
    test_ismatch();
    return 0;
}