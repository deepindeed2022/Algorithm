/***********************************************************************************
﻿ * 问题描述
　　编写一个程序，读入一组整数，这组整数是按照从小到大的顺序排列的，它们的个数N也是由用户输入的，最多不会超过20。然后程序将对这个数组进行统计，把出现次数最多的那个数组元素值打印出来。如果有两个元素值出现的次数相同，即并列第一，那么只打印比较小的那个值。
 * 输入格式：第一行是一个整数N，N £ 20；接下来有N行，每一行表示一个整数，并且按照从小到大的顺序排列。
 * 输出格式：输出只有一行，即出现次数最多的那个元素值。
*************************************************************************************/
#include <map>
#include <iostream>
int main(int argc, char const *argv[])
{
    int N = 0;
    int num = 0;
    std::cin >> N;
    std::map<int, int> counter;
    std::map<int, int>::iterator iterm;
    for (int i = 0; i < N; ++i)
    {
        std::cin >> num;
        iterm = counter.find(num);
        if(iterm == counter.end())
        {
            counter[num] = 1;
        }else
        {
            counter[num] += 1;
        }
    }

    int maxnum = 1;
    int smallfirst;
    for(std::map<int, int>::iterator iter = counter.begin();
        iter != counter.end(); ++iter)
    {
        if(iter->second > maxnum)
        {
            maxnum = iter->second;
            smallfirst = iter->first;
        }else if( iter->second == maxnum && iter->first < smallfirst )
        {
            smallfirst = iter->first;
        }
    }
    std::cout << smallfirst << std::endl;
    return 0;
}