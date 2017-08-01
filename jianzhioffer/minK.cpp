#include <iostream>
#include <vector>
using namespace std;
// class Solution {
// public:
//  // Time: O(nlogn)
//     vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
//        vector<int> n;
//        if(k > input.size())return n;
//        sort(input.begin(), input.end());
//        while(k){
//            n.insert(n.begin(), input[k-1]);
//            k--;
//        }
//        return n;
//     }
// };


class Solution {
public:
    int Partition(vector<int>& input, int begin, int end)
    {
        int low = begin;
        int high = end;

        int pivot = input[low];
        while(low < high)
        {
            while(low < high && pivot <= input[high])
                high--;
            input[low] = input[high];
            while(low < high && pivot >= input[low])
                low++;
            input[high] = input[low];
        }
        input[low] = pivot;
        return low;
    }

    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) 
    {
        int len=input.size();
        if(len == 0 || k > len) return vector<int>();
        if(len == k) return input;
        
        int start = 0;
        int end = len - 1;
        int index = Partition(input, start, end);
        while(index != (k - 1))
        {
            if(index > k - 1)
            {
                end = index - 1;
                index = Partition(input, start, end);
            }
            else if(index < k - 1)
            {
                start = index + 1;
                index = Partition(input, start, end);
            }
            else
            {
                vector<int> res(input.begin(), input.begin() + k);
                return res;
            }
        }
        vector<int> res(input.begin(), input.begin() + k);
        return res;
    }
};
int main(int argc, char const *argv[])
{
    int a[] = {3,4,6,1,3,34,434,2};
    std::vector<int> aa(a, a+8);
    Solution solve;
    std::vector<int> result = solve.GetLeastNumbers_Solution(aa, 4);
    for(int i =0; i < result.size(); i++)
    {
        std::cout << result[i] << " ";
    }
    return 0;
}