#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <utility>
using namespace std;

std::vector<string> findRelativeRanks(vector<int>& nums)
{
    priority_queue<pair<int, int> > pq;
    for(int i = 0; i < nums.size(); ++i)
    {
        pq.push({nums[i], i});
    }
    int count = 1;
    std::vector<string> res(nums.size());
    while(pq.size())
    {
        auto p = pq.top();
        pq.pop();
        if(count == 1)
            res[p.second] = "Gold Medal";
        else if(count == 2)
            res[p.second] = "Silver Medal";
        else if(count == 3)
            res[p.second] = "Bronze Medal";
        else
            res[p.second] = to_string(count);
        count++;
    }
    return res;
}
int main(int argc, char const *argv[])
{
    int a[] = {5, 4, 3, 2, 1};
    std::vector<int> v(a, a+5);
    for(auto s: findRelativeRanks(v))
    {
        std::cout << s << std::endl;
    }
    return 0;
}