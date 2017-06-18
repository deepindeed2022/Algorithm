class Solution {
public:
    int Sum_Solution(int n) {
        int sum = n;
        bool ans = (n > 0) && ((sum += Sum_Solution(n-1)) > 0);
        return sum;
    }
};
#include <iostream>
using namespace std;

#define f(x) ((((x) & 1) << 31) >> 31)
int main(int argc, char const *argv[])
{
	std::cout << f(7) << std::endl;
	return 0;
}