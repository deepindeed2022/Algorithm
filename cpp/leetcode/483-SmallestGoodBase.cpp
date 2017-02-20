#include <string>
#include <algorithm>
#include <cassert>
#include <climits>
#include <cstdlib>
using namespace std;
class Solution {
private:
    static long long sum(long long base, int maxExponent)
    {
        long long power = 1;
        long long value = 0;
        for(int i = 0; i < maxExponent + 1; ++i)
        {
            value += power;
            power *= base;
        }
        return value;
    }
public:
    string smallestGoodBase(string n) {
        long long min = LLONG_MAX;
        long long number = std::stoll(n);
        for(int maxexp = 2; ;++maxexp)
        {
            long long base = floor(pow(number, 1.0/maxexp));
            if(base == 1) break;
            if(base < min && sum(base, maxexp) == number)
                min = base;
        }
        if(min == LLONG_MAX)
            return std::to_string(number - 1);
        return std::to_string(min);
    }
};
void test_smallestGoodBase()
{
    Solution solve;
    assert(solve.smallestGoodBase("13") == "3");
    assert(solve.smallestGoodBase("4681") == "8");
    assert(solve.smallestGoodBase("1000000000000000000") == "999999999999999999");
}