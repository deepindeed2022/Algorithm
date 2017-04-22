#include <string>
#include <iostream>

using namespace std;
 
int main()
{
    int n, m;
    std::cin >> n >> m;
 
    int flag = 0; // 0:right  1:down  2:left  3:up
    int x = 0, y = 0;
    int up = 0, down = n - 1, left = 0, right = n - 1;
    while (1) {
        --m;
        if (m == 0)
        {
            std::cout << x + 1 << " " << y + 1 << std::endl;
            return 0;
        }
        if (flag == 0) {                 //right
            if (y == right) {
                ++x;
                flag = 1;
                ++up;
            }
            else 
                ++y;
            
        }
        else if (flag == 1) {        
            if (x == down) {

                --y;
                flag = 2;
                --right;
            }
            else 
                ++x;
            
        }
        else if (flag == 2) {           
            if (y == left) {
 
                --x;
                flag = 3;
                --down;
            }
            else 
                --y;
            
        }
        else if (flag == 3) {         
            if (x == up) {
                ++y;
                flag = 0;
                ++left;
            }
            else 
                --x;
            
        }
    }
    std::cout << x << y << std::endl;
    return 0;
}