#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <algorithm>
using std::swap;

template<class T>
int partition(T* arr,size_t l,size_t r)
{
	int i=l-1;int j = r;
	T target = arr[r];
	while(1)
	{
		while(arr[++i]<target||arr[--j]>target)
			if(j<=i)break;

		if(j<=i)break;

		swap(arr[i],arr[j]);
	}
	swap(arr[i],arr[r]);
	return i;
}

template <class T>
void qSort(T* arr,size_t l,size_t r)
{
	if(l>=r)return;
	int i=partition<int>(arr,l,r);
	qSort(arr,l,i-1);
	qSort(arr,i+1,r);
}
template <class T>
void print(T arr[],size_t size)
{
	for(size_t i=0;i<size;i++)
		cout<<arr[i]<<" ";
	cout<<"\n";
}
void testQuickSort()
{
	int arr[] = {1,3,5,67,4,23,5,7,3,6,4,33};
	qSort<int>(arr,0,sizeof(arr)/sizeof(int)-1);
	print<int>(arr,sizeof(arr)/sizeof(int));
}

int main()
{
	testQuickSort();
	return 1;
}