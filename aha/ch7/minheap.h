#ifndef MIN_HEAP_H_
#define MIN_HEAP_H_
#include <algorithm>
#include <cstdio>
using namespace std;
namespace aha
{
const int MAX_LEN = 101;
int minheap[MAX_LEN];
int n = 0;
void shiftdown(int minheap[MAX_LEN], const int n, int i);
int deletemin();
void shiftup(int i = n);



void shiftdown(int minheap[MAX_LEN], const int n, int i)
{
   bool flag = false;
   int t;
   while (i * 2 <= n && !flag)
   {
      // t = minheap[i] > minheap[i*2] ? i*2 : i;
      if (minheap[i] > minheap[i * 2])
         t = i << 1;
      else
         t = i;
      if (i * 2 + 1 <= n)
         t = minheap[t] > minheap[i * 2 + 1] ? i * 2 + 1 : t;
      if (t != i)
      {
         swap(minheap[t], minheap[i]);
         i = t;
      }
      else
         flag = true;
   }
}
void shiftup(int i)
{
   bool flag = false;
   if (i == 1)
      return;
   while (i != 1 && !flag)
   {
      if (minheap[i] < minheap[i / 2])
         swap(minheap[i], minheap[i / 2]);
      else
         flag = true;
      i       = i / 2;
   }
}
int deletemin()
{
   int t      = minheap[1];
   minheap[1] = minheap[n];
   n--;
   shiftdown(minheap, n, 1);
   return t;
}
}

#endif