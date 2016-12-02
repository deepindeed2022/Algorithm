#include <iostream>
#include <vector>
using namespace std;
void init_yh_triangles(std::vector< std::vector<int> >& vec)
{
    vec[0][1] = 1;

    for (int i = 1; i < vec.size(); ++i)
    {
        for (int j = 1; j <= i+1; ++j)
        {
            vec[i][j] = vec[i-1][j] + vec[i-1][j-1];
        }
    }
}
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    //n = 4;
    std::vector<std::vector<int> > vec(n, std::vector<int>(n + 1, 0));
    init_yh_triangles(vec);
    for (int i = 0; i < vec.size(); ++i)
    {
        for(int j = 1; j <= i + 1; ++j)
            std::cout << vec[i][j] << " ";
        std::cout << std::endl;
    }
    return 0;
}
