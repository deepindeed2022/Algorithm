#include <iostream>
using namespace std;
class alloc{

};
template <class T, class Alloc = alloc, size_t BufSiz = 0>
class deque{
public:
	deque(){cout << "deque" << endl;}
};
template <class T, class Sequence = deque<T> >
class stack{
public:
	stack(){cout << "stack" << endl;}
private:
	Sequence c;
};
int main(int argc, char const *argv[])
{
	stack<int> x;
	#ifdef __STL_LIMITED_DEFAULT_TEMPLATES
		cout << "Hello" <<endl;
	#endif
	return 0;
}
