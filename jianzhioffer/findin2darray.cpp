#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
 public:
   bool Find(int target, vector<vector<int>> array)
   {
      if (array.empty())
         return false;
      int col_start = 0;
      int col_end   = array.size();

      int row_start = 0;
      int row_end   = array[0].size();
      int col_mid   = (col_start + col_end) >> 1;
      int row_mid   = (row_start + row_end) >> 1;
      while (col_start < col_end && row_start < row_end)
      {
         if (array[row_mid][col_mid] == target)
            return true;
         else if (array[row_mid][col_mid] > target)
         {
            col_end = col_mid - 1;
            row_end = row_mid - 1;
         }
         else if (array[row_start][col_mid] < target)
         {
            col_start = col_mid + 1;
            row_start = row_mid + 1;
         }
         col_mid = (col_start + col_end) / 2;
         row_mid = (row_start + row_end) / 2;
      }
      return false;
   }
};
/* 在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增
 * 的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
 */
class Solution2
{
 public:
   bool Find(int target, vector<vector<int>> array)
   {
      if (array.empty()) //注意空的数组!!!!!
      {
         return false;
      }
      int line_sz   = array[0].size();
      int column_sz = array.size();

      int i = 0;
      int j = column_sz - 1;

      while (i < line_sz && j >= 0)
      {
         if (array[j][i] == target)
         {
            return true;
         }
         if (array[j][i] > target)
         {
            j--;
         }
         else
         {
            i++;
         }
      }

      return false;
   }
};
int main(int argc, char const *argv[])
{
   std::vector<vector<int>> v(3, vector<int>(3, 0));
   v[0][0] = 1;
   v[0][1] = 2;
   v[0][2] = 3;
   v[1][0] = 4;
   v[1][1] = 5;
   v[1][2] = 6;
   v[2][0] = 7;
   v[2][1] = 8;
   v[2][2] = 9;
   Solution solve;
   std::cout << solve.Find(10, v);
   return 0;
}

