// nth_element example
#include <iostream>     // std::cout
#include <algorithm>    // std::nth_element, std::random_shuffle
#include <vector>       // std::vector

bool myfunction (int i,int j) { return (i>j); }

int main () {
  std::vector<int> myvector;
  int K = 5;
  // set some values:
  for (int i = 1; i < 100; i++) myvector.push_back(i);   // 1 2 3 4 5 6 7 8 9

  std::random_shuffle (myvector.begin(), myvector.end());
  // print out content:
  std::cout << "myvector is:";
  for (std::vector<int>::iterator it=myvector.begin(); it!=myvector.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';
  // using default comparison (operator <):
  std::nth_element(myvector.begin(), myvector.begin() + K, myvector.end());
  // print out content:
  std::cout << "myvector Top K smaller:";
  for (std::vector<int>::iterator it=myvector.begin(); it!=myvector.begin() + K; ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';
  // using function as comp
  std::nth_element (myvector.begin(), myvector.begin()+K, myvector.end(), myfunction);

  // print out content:
  std::cout << "myvector Top K bigger:";
  for (std::vector<int>::iterator it=myvector.begin(); it!=myvector.begin() + K; ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  return 0;
}