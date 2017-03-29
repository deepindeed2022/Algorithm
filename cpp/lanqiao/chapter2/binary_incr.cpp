#include <bitset>
#include <iostream>
using namespace std;
void increment(std::bitset<5>& bset) {
  for (int i = 0; i < 5; ++i) {
    if (bset[i] == 1)
      bset[i] = 0;
    else {
      bset[i] = 1;
      break;
    }
  }
}
void method_1() {
  for (int i = 0; i < 32; ++i) {
    std::bitset<5> bset(i);
    std::cout << bset << std::endl;
  }
}
int main(int argc, char const* argv[]) {
  std::bitset<5> bset(0);
  for (int i = 0; i < 32; ++i) {
    std::cout << bset << std::endl;
    increment(bset);
  }

  return 0;
}