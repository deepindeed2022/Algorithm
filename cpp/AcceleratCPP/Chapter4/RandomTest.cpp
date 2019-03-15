
// random_shuffle example
#include <iostream>     // std::cout
#include <algorithm>    // std::random_shuffle, std::is_heap, std::make_heap, std::pop_heap
#include <vector>       // std::vector
#include <ctime>        // std::time
#include <cstdlib>      // std::rand, std::srand
#include <iomanip>
#include <list>
#include <string>
using namespace std;

// random generator function:
int myrandom (int i) { return std::rand()%i;}
void print(int element){std::cout<<element<<" ";}
std::vector<int> randomGenerator(const unsigned int vectorsize) {
  std::srand ( unsigned ( std::time(0) ) );
  std::vector<int> myvector;
  // set some values:
  for (int i=1; i<vectorsize; ++i) myvector.push_back(i); // 1 2 3 4 5 6 7 8 9
  // using built-in random generator:
  std::random_shuffle ( myvector.begin(), myvector.end() );
  //print out content:
  std::cout << "myvector contains:";
  /*for (std::vector<int>::iterator it=myvector.begin(); it!=myvector.end(); ++it)
    std::cout << ' ' << *it;*/
	std::for_each(myvector.begin(),myvector.end(),print);
  std::cout << '\n';
  return myvector;
}
void testMakeHeap()
{
	 std::vector<int> foo =randomGenerator(20);

  if (!std::is_heap(foo.begin(),foo.end()))
    std::make_heap(foo.begin(),foo.end());

  std::cout << "Popping out elements:";
  //std::sort_heap (foo.begin(),foo.end());
  while (!foo.empty())
  {
    std::pop_heap(foo.begin(),foo.end());   // moves largest element to back
    std::cout << ' ' << foo.back();         // prints back
    foo.pop_back();                         // pops element out of container
  }
  std::cout << '\n';
}

typedef list<char> clist;
static clist mylist ;
//输出每个元素
void print(string message="")
{
	cout<<message<<endl;
	for(auto c : mylist)
	{
		cout<<int(c)<<" "<<c<<" ";
	}
	cout<<endl;
}
bool compare(unsigned int num)
{
	return num>4&&num<7;
}
void testListRemove()
{
	 while(mylist.size() <10)
	{
		mylist.insert(mylist.end(),mylist.size());
	}
	print("原始数组");
	mylist.remove(char(2));
	print("删除char（2）");
	mylist.remove(char(2));
	print("删除char（2）");
	mylist.remove_if(compare);//删除满足compare条件的元素 compate must return bool
	print("删除满足条件之后的数组元素");
}
