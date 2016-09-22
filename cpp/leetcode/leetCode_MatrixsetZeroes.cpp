#include <vector>
#include <iostream>
#include <ctime>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int> >& matrix) {
        bool row = false, col = false;
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){
                if(matrix[i][j] == 0) {
                    if(i == 0) row = true;
                    if(j == 0) col = true;
                    matrix[0][j] = matrix[i][0] = 0;
                }
            }
        }
        for(int i = 1; i < matrix.size(); i++){
            for(int j = 1; j < matrix[0].size(); j++){
                if(matrix[i][0] == 0 || matrix[0][j] == 0) matrix[i][j] = 0;
            }
        }
        if(col){
            for(int i = 0; i < matrix.size(); i++) matrix[i][0] = 0;
        }
        if(row){
            for(int j = 0; j < matrix[0].size(); j++) matrix[0][j] = 0;
        }
    }

    void setZeroes2(vector<vector<int> > &matrix) {
        int col0 = 1, rows = matrix.size(), cols = matrix[0].size();
        for (int i = 0; i < rows; i++) {
            if (matrix[i][0] == 0) col0 = 0;
            for (int j = 1; j < cols; j++)
                if (matrix[i][j] == 0)
                    matrix[i][0] = matrix[0][j] = 0;
        }

        for (int i = rows - 1; i >= 0; i--) {
            for (int j = cols - 1; j >= 1; j--)
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            if (col0 == 0) matrix[i][0] = 0;
        }
    }
};

void print(std::vector<std::vector<int> >& v)
{
    for (std::vector<std::vector<int> >::iterator i = v.begin(); i != v.end(); ++i)
    {
        for (std::vector<int>::iterator j = (*i).begin(); j!= (*i).end(); ++j)
        {
           std::cout<< (*j) << " "; 
        }
        std::cout <<"\n";
    }
}
int main(int argc, char const *argv[])
{
    Solution solv = Solution();
    

    vector<int> ivec(10,1);
    std::vector<std::vector<int> > matrix;
    for (int i = 0; i < 10; ++i)
    {
        matrix.push_back(ivec);
    }
    matrix[1][1] = 0;
    matrix[1][9] = 0;
    matrix[3][8] = 0;
    std::cout <<"BEFORE SET ZEROS:\n";
    // print(matrix);
    clock_t start = clock();
    for (int i = 0; i < 1000; ++i)
    {
        std::vector<std::vector<int> > matrix2(matrix);
    }
    clock_t idel = clock();
    for (int i = 0; i < 1000; ++i)
    {
        std::vector<std::vector<int> > matrix2(matrix);

        solv.setZeroes2(matrix);
    }
    clock_t end = clock();
    std::cout <<"AFTER SET ZEROS:" << (end + start-2*idel)<< "CPU Clock\n";
    // print(matrix);
    return 0;
}