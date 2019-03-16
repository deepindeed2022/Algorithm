#include <algorithm>
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;
template <int lambda, typename T>
struct pluslambda
{
    T operator()(T a, T b)
    {
        return a + lambda*b;
    }
};
template <typename T>
void test()
{
    T a[] = {1 , 2 , 3,  4};
    vector<T> aa(a, a+ 4);
    T b[] = {1, 1, 1, 2, 2};
    vector<T> bb(b, b + 5);
    vector<T> loss;
    transform(aa.begin(), aa.end(), bb.begin(), std::back_inserter(loss), pluslambda<2, T>());
    for(int i = 0; i < loss.size(); ++i)
    {
        assert(aa[i] + 2*bb[i] == loss[i] || aa[i] + 2*bb[i] - loss[i] < 1e-6 );
    }
}
int main(int argc, char const *argv[])
{

    test<float>();
    test<int>();
    return 0;
}