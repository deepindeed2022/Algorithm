#include <algorithm>
#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;

class Node {
public:
   int x;
   int y;

   Node() {
      x = 0;
      y = 0;
   }
};

bool compare(Node a, Node b)
{
   if (a.x > b.x)
      return true;
   else if (a.x < b.x)
      return false;
   else if (a.y < b.y)
      return true;
   return false;
}

int main(int argc, char const *argv[]) {
   int n;
   std::cin >> n;
   std::vector<Node> nodes(n, Node());
   for (int i = 0; i < n; ++i)
      std::cin >> nodes[i].x >> nodes[i].y;

   std::sort(nodes.begin(), nodes.end(), compare);

   vector<Node> result(0);
   int max_y = 0;
   for (int i = 0; i < n; ++i) {
      if (nodes[i].y >= max_y) {
         result.push_back(nodes[i]);
         max_y = nodes[i].y;
      }
   }

   for (int i = result.size() - 1; i >= 0; --i) {
      printf("%d %d\n", result[i].x, result[i].y);
   }

   return 0;
}