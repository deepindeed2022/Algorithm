//!-*- encode:utf8 -*-
#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <utility>
using namespace std;
/***
 Priority queue
Priority queues are a type of container adaptors, specifically designed such that its first element is always the greatest of the elements it contains, according to some strict weak ordering criterion.

This context is similar to a heap, where elements can be inserted at any moment, and only the max heap element can be retrieved (the one at the top in the priority queue).

Priority queues are implemented as container adaptors, which are classes that use an encapsulated object of a specific container class as its underlying container, providing a specific set of member functions to access its elements. Elements are popped from the "back" of the specific container, which is known as the top of the priority queue.

The underlying container may be any of the standard container class templates or some other specifically designed container class. The container shall be accessible through random access iterators and support the following operations:
empty()
size()
front()
push_back()
pop_back()

The standard container classes vector and deque fulfill these requirements. By default, if no container class is specified for a particular priority_queue class instantiation, the standard container vector is used.

Support of random access iterators is required to keep a heap structure internally at all times. This is done automatically by the container adaptor by automatically calling the algorithm functions make_heap, push_heap and pop_heap when needed.
*/
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
            res[p.second] = std::to_string(count);
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