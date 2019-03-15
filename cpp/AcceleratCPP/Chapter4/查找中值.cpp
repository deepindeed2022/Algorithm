#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <vector>
using std::vector;
double median(std::vector<double> vec)
{
	typedef vector<double>::size_type vec_sz;
	vec_sz size = vec.size();
	if(0== size)
	{
		throw domain_error("median of an empty vector");
	}
	sort(vec.begin(),vec.end());
	vec_sz mid = size/2;
	return size%2==0?(vec[mid]+vec[mid-1])/2:vec[mid];
}
void print(int arr[],int length)
{
	for(int i=0;i<length;i++)
	{
		cout<<*(arr+i) <<" " ;
	}
	cout<<endl;
}
int main()
{
	int arr[] = {2,3,4,9,6,3,5,7,3,7,32,6,335,6};
	median(arr);
	print(arr);
	return 1;
}