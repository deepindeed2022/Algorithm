/**
 * 给定一个序列，每次询问序列中第l个数到第r个数中第K大的数是哪个。
 * 输入格式
    第一行包含一个数n，表示序列长度。
    第二行包含n个正整数，表示给定的序列。
    第三个包含一个正整数m，表示询问个数。
    接下来m行，每行三个数l,r,K，表示询问序列从左往右第l个数到第r个数中，
    从大往小第K大的数是哪个。序列元素从1开始标号。
 * 输出格式
    总共输出m行，每行一个数，表示询问的答案。
 **/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
bool compare(int x, int y)
{
    return x >= y;
}
int random_search_kth(std::vector<int>& vec, int k)
{

    std::sort(vec.begin(), vec.end(), compare);
    return vec[k - 1];
}
// void print(int x)
// {
//     std::cout << x << " ";
// }
int main(int argc, char const *argv[])
{
    int seqn;
    int m;
    std::cin >> seqn;
    std::vector<int> vec(seqn + 1, 0);
    for (int i = 1; i <= seqn; ++i)
    {
        std::cin >> vec[i];
    }
    std::cin >> m;
    int l = 0;
    int r = 0;
    int k = 0;
    for(int i = 0; i < m; ++i)
    {
        std::cin >> l;
        std::cin >> r;
        std::cin >> k;
        if(k > r-l+1) return 1;
       
        std::vector<int> vect(vec.begin() + l, vec.begin() + r + 1);
        
        std::cout << random_search_kth(vect, k) << std::endl;
        //for_each(vect.begin(), vect.end(), print);
        //std::cout << std::endl;
    }

    return 0;
}