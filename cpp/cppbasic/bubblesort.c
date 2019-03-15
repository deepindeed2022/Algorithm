/**
 * C实现的冒泡排序算法：
 * 被排序类型为struct student数据类型，通过比较分数进行排序
 * 1. C语言要先声明后使用，尤其是for循环的循环变量要在for之间
 * 进行声明使用；
 * 2. C没有命名空间的说法；
 * 3. C中最主要的就是指针了，各种指针，指针函数可以参考template_gen.cpp；
 * 4. struct是可以直接进行赋值操作的，就像直接用memcpy或者memset进行内存
 *    赋值似的。 当前前提是struct中没有指针变量，呵呵，否则会造成内存空间
 *    泄漏等等问题，用C++ shared_ptr试试；
 * 
 * auther: wenlong.cao
 * date: 2017-3-25
 **/
#include <stdio.h>
//#define __STATIC__ 1
#include <stdlib.h>
struct student
{
	char name[12];
	char score;
}*stuPtr;
int main(int argc, char const *argv[])
{
#ifdef __STATIC__
	// struct student array declaration, or you malloc n struct
	struct student a[100];
#else
	struct student* a; 
#endif
	struct student t;
	int i, j, n;
	FILE* f;
	if(argc < 2)
	{
		f = fopen("bubblesort_testcase.txt", "r");
	}
	else
	{
		f = fopen(argv[1], "r");
	}
	fscanf(f, "%d", &n);

#ifndef __STATIC__
	a = (student*)malloc(sizeof(student)*n);
	if(a == NULL) exit(1);
	
#endif

	for (i = 0; i < n; ++i)
	{
		fscanf(f, "%s %d", a[i].name, &a[i].score);
	}
	// start bubblesort
	for (i = 0; i < n-1; ++i)
	{
		for (j = 0; j < n-i; ++j)
		{
			// every time get the current state's max element move to last
			if(a[j].score < a[j+1].score)
			{
				// C++ have swap(a, b) method in <utility> header file after C++
				// before C++11 in <algorithm> header file 
				t = a[j];  a[j] = a[j+1];  a[j+1]=t;
			}
		}
	}
	for (i = 0; i < n; ++i)
	{
		printf("%s %d\n", a[i].name, a[i].score);
	}
#ifndef __STATIC__
	free(a);
#endif
	return 0;
}