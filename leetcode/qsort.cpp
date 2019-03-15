#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::clog;
#include <algorithm>
using namespace std;
void print(int arr[],int length)
{
	for(int i=0;i<length;i++)
	{
		cout<<*(arr+i) <<" " ;
	}
	cout<<endl;
}
int partition(int* a,int l,int r)
{
        int i=l-1,j=r,v=a[r];
        while(1)
        {
            while(a[++i]<v||a[--j]>v) if(j<=i) break;

            if(i>=j)
            break;

            swap(a[i],a[j]);
        }
        swap(a[i],a[r]);
        return i;
}
void qsort(int* a,int l,int r)
{
    if(l>=r) return;
    int i = partition(a,l,r);
    qsort(a,l,i-1);
    qsort(a,i+1,r);
}
void testQuickSort()
{
	int arr[] = {1,3,5,67,4,23,5,7,3,6,4,33};
	qsort(arr,0,sizeof(arr)/sizeof(int)-1);
	print(arr,sizeof(arr)/sizeof(int));

	int arr1[] = {1,4};

	qsort(arr1,0,sizeof(arr1)/sizeof(int)-1);
	print(arr1,sizeof(arr1)/sizeof(int));

	int arr2[] = {4};
	qsort(arr2,0,sizeof(arr2)/sizeof(int)-1);
	print(arr2,sizeof(arr2)/sizeof(int));
}

int main(int argn,char* argc[])
{
	int* q =new int[10];
	testQuickSort();
	return 1;
}