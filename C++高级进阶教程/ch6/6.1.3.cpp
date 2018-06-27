#include <iostream>
using namespace std;
template <typename T, int Length>
class Array{
	int size;
	T Elements[Length];
public:
	int Size(){return Length;}
	Array():size(Length){}
	T& operator[](int i) {
		return Elements[i];
	}
	template <typename T, int Length>friend ostream& operator<<(ostream&, const Array<T, Length>&);
};
template <typename T, int Length>
ostream& operator<<(ostream& out, const Array<T, Length>& a)
{
	for (int i = 0; i < a.size; ++i)
	{
		out<< a.Elements[i];
		if(typeid(a.Elements[i]) == typeid(int)||typeid(a.Elements[i]) == typeid(double))
			out <<" ";
	}
	return out;
}

int main(int argc, char const *argv[])
{
	int k = 0;
	Array<double,3> a1d;
	a1d[0] = 1.1;
	a1d[1] = 2.2;
	a1d[2] = 3.3;
	std::cout << a1d << std::endl;
	Array<Array<int, 3>, 4> a2d;
	for(int i = 0; i < a2d.Size(); i++)
	{
		for (int j = 0; j < a2d[i].Size(); ++j)
		{
			a2d[i][j] = ++k;
		}
	}
	std::cout << a2d << std::endl;
	return 0;
}