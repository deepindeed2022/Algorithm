#include <cmath>
using namespace std;
class Solution {
public:
    int jumpFloorII(int number) {
		if(number <= 1)
            return 1;
       	else
        {
        	return pow(2, number - 1);    
        }
    }
};