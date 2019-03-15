#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <vector>
using std::vector;
#include <algorithm>
using std::sort;
#include <ctime>        // std::time
template<class T>
void print(T element){std::cout<<element<<" ";}
template<class T>
std::vector<T> randomGenerator(const unsigned int vectorsize) 
{
  std::srand ( unsigned ( std::time(0) ) );
  std::vector<T> myvector;
  // set some values:
  for (int i=1; i<vectorsize; ++i) myvector.push_back(i); // 1 2 3 4 5 6 7 8 9
  // using built-in random generator:
  std::random_shuffle( myvector.begin(), myvector.end() );
  //print out content:
  std::cout << "myvector contains:";
  /*for (std::vector<int>::iterator it=myvector.begin(); it!=myvector.end(); ++it)
    std::cout << ' ' << *it;*/
  std::for_each(myvector.begin(),myvector.end(),print<T>);
  std::cout << '\n';
  return myvector;
}
double median(std::vector<double> vec)
{
	typedef vector<double>::size_type vec_sz;
	vec_sz size = vec.size();
	if(0== size)
		return -1;
	sort(vec.begin(),vec.end());
	vec_sz mid = size/2;
	return size%2==0?(vec[mid]+vec[mid-1])/2:vec[mid];
}

int main()
{
	std::vector<double> arr=randomGenerator<double>(11);
	cout<<median(arr);
	
	return 1;
}