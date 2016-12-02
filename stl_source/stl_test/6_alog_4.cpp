#include <iterator>
#include <functional>
#include <iostream>
#include <vector>
#include <numeric>
#include <fstream>
#include <sstream>      // std::ostringstream
using namespace std;
int main(int argc, char const *argv[])
{
#if __cplusplus <= 201103L
    std::ofstream fs;
    fs.open("result.txt", std::ios::app);
    std::ostream_iterator<int> oite(fs, " ");
    int ia[5] = {1,2,3,4,5};
    std::vector<int> v(ia, ia + 5);
    std::partial_sum(v.begin(), v.end(), oite);
    fs << std::endl;
    std::partial_sum(v.begin(), v.end(), oite, std::minus<int>());
    fs << std::endl;
#endif

    std::ostringstream bar (std::ostringstream::ate);  // out|ate

    bar.str("Test string");
    bar <<" " <<10;
    bar << '\t';
    bar << 01234;
    bar << '\t';
    bar << 0xFFFF;
    const std::string s = bar.str();
    std::cout << s << std::endl;
    std::cout << bar.str() << '\n';

    return 0;
}