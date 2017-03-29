#include <vector>
#include <iostream>
using namespace std;

int find_index(std::vector<int>& vec,const int value)
{
    for (int i = 0; i < vec.size(); ++i)
    {
        if(vec[i] == value)
            return i+1;
    }
    return -1;
}
int main(int argc, char const *argv[])
{
    int n;
    int a;
    std::cin >> n;
    std::vector<int> vec(n, 0);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> vec[i];
    }
    
    cin >> a;
    std::cout << find_index(vec, a);
    return 0;
}
