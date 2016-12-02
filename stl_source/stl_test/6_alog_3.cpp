/**************************************************************************
 * @description:
 * This file is a practice for output format and std lib numeric function
 * I use the function:
 *  accumulate
 *  adjacent_differnce
 *  copy
 *  for_each
 * Set the output format using:
 *  setw to set the  width
 * @author: wenlong.cao
 * @create： 2016-11-28
 * 
 **************************************************************************/
#include <numeric>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;
#define INFOW 25
#define NUMW 3
void print(int a)
{
    std::cout<< std::setw(NUMW) << a << " ";
}
int assign(int x, int y)
{
    return x;
}
int init(int& a)
{
    a = 0;
}
int main(int argc, char const *argv[])
{
    int ia[] = {22,30,30,17,33,40,17,23,22,12,20};
    const int size = sizeof(ia)/sizeof(int);
    std::vector<int> ivec(ia, ia + size);
    int isum = std::accumulate(ivec.begin(), ivec.end(), 0);
    std::cout << std::setw(INFOW) <<"acculumate an array:" <<isum << std::endl;
    int result[size];
    
    std::sort(ia, ia + size);
    std::adjacent_difference(ia, ia +size,  result);
    std::cout << std::setw(INFOW) << "current `ia` is:";
    std::for_each(ia, ia + size, print);
    std::cout << std::endl;

    std::cout << std::setw(INFOW)<< "now `ia` is:";
    std::for_each(result, result + size, print);
    std::cout << std::endl;

    std::cout << std::setw(INFOW)<< "adjacent_difference copy:";
    std::adjacent_difference(ia, ia + size, result, assign);
    std::for_each(result, result + size, print);
    std::cout << std::endl;
    std::cout << std::setw(INFOW)<< "after init `result`:";
    std::for_each(result, result + size, init);
    std::for_each(result, result + size, print);
    std::cout << std::endl;

    std::cout << std::setw(INFOW)<<"using algroithm copy:";
    std::copy(ia, ia + size, result);
    std::for_each(result, result + size, print);
    std::cout << std::endl;

    
    return 0;
}