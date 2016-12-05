/**********************************************************************************************
Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
/**********************************************************************************************/
#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>
using std::vector;
int minimumTotal(vector<vector<int> >& triangle) {
    assert(triangle.begin() != triangle.end());
    int size = triangle.size();
    std::vector<int> minVec(size, 0);
    for(int i = size - 1; i >= 0; --i)
    {
        for(int j = 0; j <= i; ++j)
        {
            if(i == size - 1)
                minVec[j] = triangle[i][j];
            else
                minVec[j] = std::min(minVec[j]+triangle[i][j], minVec[j+1]+triangle[i][j]);
        }
    }
    return minVec[0];//(*std::min_element(minVec.begin(), minVec.end()));
}

int main(int argc, char const *argv[])
{
    vector<vector<int> > triangle(2, std::vector<int>(2, 0));
    triangle[0][0] = 1;
    triangle[1][0] = 2;
    triangle[1][1] = 3;
    std::cout << minimumTotal(triangle) << std::endl; 
    return 0;
}