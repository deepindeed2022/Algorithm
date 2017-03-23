#include <vector>
#include <string>
#include <iostream>
#include <set>
using namespace std;

int majorityElement(vector<int>& nums) {
	int major = -1; int count = 1;
	for(int i = 0; i < nums.size(); ++i)
	{
		if(count == 0)
		{
			major = nums[i];
			count = 1;
		}
		else
		if(nums[i] == major)
		{
			count++;
		}
		else if(nums[i] != major)
		{
			count--;
		}
	}
	return major;

}

int majorityElement_2(vector<int>& nums)
{
	std::sort(nums.begin(), nums.end());
	return nums[nums.size()/2];
}


vector<int> majorityElement(vector<int>& nums) {
    int major_1, major_2 = -1;
    float count_1 = 1;
   	float count_2 = 1;
   	vector<int> ret;
   	if(nums.size() == 0) return ret;
   	if(nums.size() < 3) 
   	{
   		set<int> third(nums.begin(), num.end());
   		std::vector<int> a(third.begin(), third.end());
   		return a;
   	}
    for(int i = 0; i  < nums.size(); ++i)
    {
    	if(count_1 == 0 || count_2 == 0)
    	{
    		if(count_1 == 0)
    		{
    			major_1 = nums[i];
    			count_1 = 1;
    		}else
    		{
    			major_2 = nums[i];
    			count_2 = 1;
    		}
    	}
    	else 
    	if(nums[i] != major_1 && nums[i] != major_2)
    	{
    		count_1-=1; count_2 -= 1;
    	}
    	else if(nums[i] == major_1)
    	{
    		count_1++;
    	}else if(nums[i] == major_2)
    	{
    		count_2++;
    	}
    }
    if(count_1 > nums.size()/3)
    	ret.push_back(major_1);
    if(count_2 > nums.size()/3)
    ret.push_back(major_2);
    return ret;
}