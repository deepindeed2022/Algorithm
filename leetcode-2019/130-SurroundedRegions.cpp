#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

class Solution {
public:
    void DFS (vector<vector<char>>& board, int i, int j) {
        board[i][j] = '1';
        if (i-1 > -1 && board[i-1][j] == 'O') DFS(board,i-1,j);
        if (i+1 < board.size() && board[i+1][j] == 'O') DFS(board,i+1,j);
        if (j-1 > -1 && board[i][j-1] == 'O') DFS(board,i,j-1);
        if (j+1 < board[0].size() && board[i][j+1] == 'O') DFS(board,i,j+1);        

    }

    void solve(vector<vector<char>>& board) {
        if (board.size() < 2) return ;

        for (int j = 0; j < board[0].size(); ++j) {
            if (board[0][j] == 'O') DFS(board,0,j);
            if (board[board.size()-1][j] == 'O') DFS(board,board.size()-1,j);
        }

        for (int i = 1; i < board.size()-1; ++i) {
            if (board[i][0] == 'O') DFS(board,i,0);
            if (board[i][board[0].size()-1] == 'O') DFS(board,i,board[0].size()-1);
        }

        for (int i = 0; i < board.size(); ++i)
            for (int j = 0; j < board[0].size(); ++j) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                else if (board[i][j] == '1') board[i][j] = 'O';
            }
    }
};


int main(int argc, char const *argv[])
{
    int n, m;
    std::ifstream cin("130-SurroundedRegions.txt");
    cin >> n >> m;
    char c;
    std::vector<std::vector<char>> v(n, std::vector<char>(10, ' '));
    for(int i =0; i  < n; i++)
    for(int j = 0; j < m; j++)
    {
        cin >> c;
        v[i][j] = c;
    }
    Solution s;
    s.solve(v);
    for(int i =0; i  < n; i++) {
        for(int j = 0; j < m; j++)
        {
            std::cout << v[i][j]<<" ";
        }
        std::cout << "\n";
    }
    return 0;
}