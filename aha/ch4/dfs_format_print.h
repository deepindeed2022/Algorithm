#include <utility>
#include <vector>
#include <string>
#include <iostream>
using namespace std;
/**
 * @param path[in] 输入的结果路径，其中元素为不同节点的位置坐标
 * @param w, h[in] 该路径是在一个w*h的平面上进行绘制
 **/
void format_path(std::vector<std::pair<int, int>> &path,
				  int w, int h, ostream& os = std::cout)
{
   std::vector<std::vector<std::string>> result(
      h, std::vector<std::string>(w, "-  "));
#define x first
#define y second
   int ii = 0;
   for (int i = 0; i < path.size(); ++i)
   {
      result[path[i].x][path[i].y] = "*  ";
   }
   os << "\t   ";
   for (int j = 0; j < w; ++j) os << j << "  ";
   os << "\n";
   for (int i = 0; i < h; ++i)
   {
      os << "\t " << i << " ";
      for (int j = 0; j < w; ++j)
      {
         os << result[i][j];
      }
      os << "\n";
   }

#undef x
#undef y
}
