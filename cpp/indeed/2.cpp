#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

static void read_vecs(std::vector<int> &x, std::vector<int> &y, const int n) 
{
   int tx, ty;
   for (int i = 0; i < n; ++i) {
      std::cin >> tx >> ty;
      x.push_back(tx);
      y.push_back(ty);
   }
}

inline int calc(std::vector<int> &x, std::vector<int> &y, std::vector<int> &tx,
                std::vector<int> &ty, std::vector<int> &order, int n) {
   int result = 0;
   for (int i = 0; i < n; ++i)
      result += abs(x[i] - tx[order[i]]) + abs(y[i] - ty[order[i]]);
   return result;
}

int robotWalk(std::vector<int> &x, std::vector<int> &y, std::vector<int> &tx,
              std::vector<int> &ty, int n) {
   std::vector<int> order;
   for (int i = 0; i < n; ++i)
      order.push_back(i);
   int ans = calc(x, y, tx, ty, order, n);
   while (next_permutation(order.begin(), order.end())) {
      int result = calc(x, y, tx, ty, order, n);
      if (ans > result)
         ans = result;
   }
   return ans;
}

int main(int argc, char const *argv[])
{
   int n, t;
   std::cin >> n >> t;
   std::vector<int> x, y;
   read_vecs(x, y, n);
   int total = 0;
   for (int i = 0; i < t; ++i) 
   {
      std::vector<int> tx, ty;
      read_vecs(tx, ty, n);
      total += robotWalk(x, y, tx, ty, n);
      x = tx;
      y = ty;
   }
   std::cout << total << std::endl;
   return 0;
}
