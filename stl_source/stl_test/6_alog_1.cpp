// This program try to assign a new value to a const_iterator, because the 
// the sort operation will change the sequence data. So, there will throw
// out a lots of exception error.
// from stl源码分析 p291
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    int ia[] = {22,30,30,17,33,40,17,23,22,12,20};
    std::vector<int> iv(ia, ia + sizeof(ia)/sizeof(int));
    std::vector<int>::const_iterator cite1 = iv.begin();
    std::vector<int>::const_iterator cite2 = iv.end();
    std::sort(cite1, cite2);
    
    return 0;
}
