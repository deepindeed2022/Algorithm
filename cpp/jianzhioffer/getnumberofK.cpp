/**
 * 统计一个数字在排序数组中出现的次数。
 * 这个主要是是在考察二叉搜索的应用。尤其是注意当碰到有序的数组的时候
 */
class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        if(data.empty()) return 0;
        int number = 0;
        int first = getfirstindex(data, k, 0, data.size() - 1);
        int last = getlastindex(data, k, 0, data.size() - 1);
        if(first > -1 && last > -1)
        	number = last - first + 1;
       	return number;

    }
private:
	int getfirstindex(vector<int>& data, int k, int start, int end)
	{
		if(start > end)
			return -1;
		int mid = start + (end - start)/2;
		if(data[mid] == k)
		{
			if(mid == start || (data[mid - 1] != k))
				return mid;
			else
			{
				end = mid - 1;
			}
		}else{
			if(data[mid] > k)
				end = mid -1;
			else{
				start = mid + 1;
			}
		}
		return getfirstindex(data, k, start, end);
	}
	int getlastindex(std::vector<int>& data, int k, int start, int end)
	{
		if(start > end)
		{
			return -1;
		}
		int mid = start + (end - start)/2;
		if(data[mid] == k)
		{
			if(mid == end|| (data[mid+1]!= k))
				return mid;
			else
				start = mid + 1;
		}
		else{
			if(data[mid] > k)
				end = mid - 1;
			else
				start = mid + 1;
		}
		return getlastindex(data, k, start, end)
	}
};