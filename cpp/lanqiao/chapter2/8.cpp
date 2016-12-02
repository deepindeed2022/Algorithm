#include <iostream>
#include <stdlib.h>
int sum_arr_num(char a[], const int n)
{
    int result = 0;
    for (int i = 0; i < n; ++i)
    {
        result += a[i] - '0';
    }
    return result;
}
int main(int argc, char const *argv[])
{
    char a[10] = {'0'};
    int n;
    std::cin >> n;
    //n = 52;
    for (int i = 10001; i <=99999; ++i)
    {
        itoa(i, a, 10);
        
        if(a[0] == a[4] && a[1] == a[3] && sum_arr_num(a, 5) == n)
        {
            std::cout << i << std::endl;
        }
    }
    for (int i = 100001; i <=999999; ++i)
    {
        itoa(i, a, 10);

        if(a[0] == a[5] && a[1] == a[4] && a[2] == a[3] && sum_arr_num(a, 6) == n)
            std::cout << i << std::endl;
    }
    return 0;
}