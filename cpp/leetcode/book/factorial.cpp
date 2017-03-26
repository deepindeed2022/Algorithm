#include <iostream>

#include <sys/time.h>
static long get_current_time()
{
        struct timeval tv;
        gettimeofday(&tv, NULL);
        return tv.tv_sec * 1000000 + tv.tv_usec;
}

int factorial(unsigned int a)
{
    if(a == 1) return 1;
    if(a == 2) return 2;
    if(a > 2) return a* (factorial(a-1));
}

int main(int argc, char const *argv[])
{
    long start, end;
    start = get_current_time();
    for (int i = 100; i <= 1100; ++i)
    {
        factorial(i);
        //std::cout << perm(i) << ",";
    }
    end = get_current_time();
    std::cout << end - start<< "us" << std::endl;
    return 0;
}