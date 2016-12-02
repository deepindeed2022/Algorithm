#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>

using namespace std;

int binary_search_kth(std::vector<int>& vec, int l, int r, int k)
{
    assert(l < r);
    std::sort(vec[l], vec[r]);
    return vec[r - k];
}
int main(int argc, char const *argv[])
{
    int a[] = {9,8,7,6,5,4,3,2,1,0,11,14};
    std::vector<int> vec(a, a+12);
    std::cout << binary_search(vec, 0, 12, 3)<< std::endl;
    return 0;
}