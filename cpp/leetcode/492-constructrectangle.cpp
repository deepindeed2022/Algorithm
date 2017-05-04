#include <vector>
#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;
vector<int> constructRectangle(int area) 
{
    vector<int> res;
    // 构造尽可能接近正方形的长方形，面积是
    for(int i = floor(sqrt(area)); i <= area; ++i)
    {
        int w = area/i;
        if(w*i == area)
        {
            res.push_back(max(i, w));
            res.push_back(min(i, w));
            return res;
        }
    }
    return res;
}
int main(int argc, char const *argv[])
{
    for(auto i: constructRectangle(5)) std::cout << i << " "; std::cout << std::endl;
    for(auto i: constructRectangle(12)) std::cout << i <<" "; std::cout << '\n';
    return 0;
}