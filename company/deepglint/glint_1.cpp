#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#include <fstream>

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int k = 0;
    std::ifstream cin("glint_1.txt");
    cin >> k;
    int type = 0, p = 0;
    int d = 1;
    for(int i = 0; i < k; i++) {
    	cin >> type >> p;
    	switch(type) {
    		case 1:
    			d += p;
    			break;
    		case 2:
    			d *= p;
    			break;
    		case 3:
    			d = ceil(float(d)/float(p));
    			break;
    		default:
    			break;
    	}
    }
    std::cout << d << std::endl;
    return 0;
}
