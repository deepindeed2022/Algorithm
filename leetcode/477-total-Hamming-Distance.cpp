#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int totalHammingDistance(vector<int>& nums) 
{
    int n = nums.size();
    int mask = 0x01;
    int nozero;
    long long total = 0;
    int looptime = 31;
    while(looptime-- > 0)
    {
    	nozero = 0;
    	for(int i = 0; i < n; ++i)
    	{
    		if((mask&nums[i])!= 0) 
    		{
    			nozero++;
    		}
    	}
    	//std::cout << mask << std::endl;
    	total += (n - nozero)*(nozero);
    	mask <<= 1;
    }
    return total;

}
int main(int argc, char const *argv[])
{
	int a[] = { 4, 14, 2};
	vector<int> vec(a, a+3);
	std::cout << totalHammingDistance(vec) << std::endl;

	return 0;
}