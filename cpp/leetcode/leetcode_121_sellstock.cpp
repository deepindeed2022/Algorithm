#include <vector>
using std::vector;
#include "utility.h"
#include <climits>
#include <algorithm>
int maxProfit(vector<int>& prices) {
    int min = INT_MAX;
    int profit = 0;
    for(int i=0; i< prices.size(); ++i)
    {
        if(prices[i] <= min) min = prices[i];
        else
        {
            profit = std::max(profit, prices[i] - min);
        }
    }
    return profit;
}
void test_maxProfit()
{
    int i_arr[] = {7, 1, 5, 3, 6, 4};
    size_t count = sizeof(i_arr)/sizeof(int);
    vector<int> prices(i_arr, i_arr + count);

    assert(5 == maxProfit(prices));
}
int main(int argc, char const *argv[])
{
    test_maxProfit();
    return 0;
}