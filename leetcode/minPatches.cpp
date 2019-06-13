#include <vector>
#include <iostream>
using namespace std;
int minPatches(vector<int>& nums, int n) {
    long miss = 1, added = 0, i = 0;
    while (miss <= n) {
        if (i < nums.size() && nums[i] <= miss) {
            miss += nums[i++];
        } else {
            miss += miss;
            added++;
        }
    }
    return added;
}
int main()
{
	vector<int> a;
    a.insert(a.end(), 2);
	a.insert(a.end(), 3);
	int n = 6;
	
	std::cout<< minPatches(a, n) <<std::endl;
    return EXIT_SUCCESS;
}