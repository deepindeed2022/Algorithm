
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[]) {
  int num;
  std::cin >> num;
  std::vector<int> v(num, 0);
  for (int i = 0; i < num; ++i) {
    std::cin >> v[i];
  }
  std::sort(v.begin(), v.end());
  for (int i = 0; i < num; ++i) {
    std::cout << v[i] << " ";
  }
  return 0;
}
