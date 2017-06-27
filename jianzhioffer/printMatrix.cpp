#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> printMatrix(vector<vector<int> >& matrix) {
    	
    	vector<int> result;
        if(matrix.empty()) return result;
    	int rlen = matrix[0].size();
    	int clen = matrix.size();
    	int j = 0;
        int i = 0;
    	int istart = 0;
    	int iend = clen;
    	int jstart = 0;
    	int jend = rlen;
    	int circle = ((rlen < clen ? rlen : clen) - 1)/2 + 1;//圈数
	    for(int k = 0; k < circle; k++)
	    {
	    	for(j = jstart; j < jend; j++) result.push_back(matrix[istart][j]);
	    	istart++;
	    	for(i = istart; i < iend; i++) result.push_back(matrix[i][jend - 1]);
	    	jend--;

	    	if(istart < iend)
	    	for(j = jend - 1; j >= jstart; j--) result.push_back(matrix[iend -1][j]);
	    	iend--;
            if(jstart < jend)
            	for(i = iend - 1; i >= istart; i--) result.push_back(matrix[i][jstart]);
	    	jstart++; 
	    }
        return result;
    }
};
int main(int argc, char const *argv[])
{
	Solution solve;
	std::vector< vector<int> > v(5, vector<int>(1, 0));
    v[0][0] = 0;
    v[1][0] = 1;
    v[2][0] = 2;
    v[3][0] = 3;
    v[4][0] = 4;

	std::cout << "\n-----------------------------\n";
	vector<int> a = solve.printMatrix(v);
	for(int i = 0; i < a.size(); ++i)
		std::cout << a[i] <<" ";

	std::vector< vector<int> > v2(1, vector<int>(5, 0));
	for(int i = 0;  i < 5; ++i) v2[0][i] = i;

	std::cout << "\n-----------------------------\n";
	vector<int> a2 = solve.printMatrix(v2);
	for(int i = 0; i < a2.size(); ++i)
		std::cout << a2[i] <<" ";
	return 0;
}