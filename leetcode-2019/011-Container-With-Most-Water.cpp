#include <vector>
#include <iostream>
using namespace std;
// Time Limit Exceeded
// class Solution {
// public:
//     int maxArea(vector<int>& height) {
//         int sz = height.size();
        
//         int max_area = 0;
//         for(int i = 0; i < sz; i++) {
//         	for(int j = i + 1; j < sz && j!= i; j++) {
//         		max_area = std::max(max_area, (j - i)* std::min(height[j], height[i]));
//         	}
//         }
//         return max_area;
//     }
// };
class Solution {
public:
    int maxArea(vector<int>& height) {
        int sz = height.size();
        
        int max_area = 0;
        int i = 0; 
        int j = sz -1;
        while(i < j) {
        	int min_value = std::min(height[i], height[j]);
        	max_area = std::max(max_area, min_value * (j -i));
        	if(min_value == height[i]) {
        		i++;
        		while(j >= i && height[i] < min_value) i++;
        	} else {
        		j--;
        		while(j >= i && height[j] < min_value) j--;
        	}
        }
        return max_area;
    }
};
int main(int argc, char const *argv[])
{
	Solution s;
	std::vector<int> height = {1,8,6,2,5,4,8,3,7};
	std::cout << s.maxArea(height) << std::endl;
	return 0;
}