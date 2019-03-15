#include <iostream>
#include <vector>
#include <cassert>
using namespace std;
void rotate(std::vector< std::vector<int> >& mat)
{
    const int n = mat.size();
    // 沿着副对角线进行对折一次
    for(int i = 0; i < n; ++i)
    {
        for(int j= 0; j < n-i; ++j )
        {
            std::swap(mat[i][j], mat[n-1-j][n-1-i]);
        }
    }
    // 沿着中心水平线进行对折
    for(int i = 0; i < (n>>1); ++i)
    {
        for(int j = 0; j < n; ++j)
            std::swap(mat[i][j], mat[n-1-i][j]);
    }
}
void test_rotate_matrix()
{
    const int n = 4;
    std::vector< std::vector<int> >  mat(n, std::vector<int>(n, 0));
    mat[0][0] = 1;
    mat[0][1] = 2;
    mat[0][2] = 1;
    mat[0][3] = 2;

    mat[1][0] = 3;
    mat[1][1] = 4;
    mat[3][0] = 3;
    mat[3][1] = 4;
    
    rotate(mat);
    assert(mat[0][3] == 1);
    assert(mat[1][3] == 2);
    assert(mat[0][0] == 3);
    assert(mat[1][0] == 4);
    std::cout << "TEST PASSED" <<std::endl;
}
int main(int argc, char const *argv[])
{
    test_rotate_matrix();
    return 0;
}