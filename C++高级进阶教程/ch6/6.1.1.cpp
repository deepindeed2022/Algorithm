#include <iostream>
using namespace std;
template <typename T, int Size>
class Average{
	T Element[Size];
	T average_value;
public:
	Average(T* in) {
		average_value = (T)0;
		for (int i = 0; i < Size; ++i)
		{
			Element[i] = in[i];
			average_value += in[i];
		}
		average_value/=Size;
	}
	void show() {
		std::cout << "The elements are:";
		for(int i = 0 ; i < Size; i++)
		{
			std::cout << Element[i] <<" ";
		}
		std::cout << std::endl << "The average is :" << average_value << std::endl;
	}
};
int main(int argc, char const *argv[])
{
	int arr_int[3] = {3,6,9};
	double arr_db[4] = {1.1, 2.2, 4.4, 8.8};
	Average<int, 3> ia(arr_int);
	Average<double, 4> da(arr_db);
	ia.show();
	da.show();
	return 0;
}