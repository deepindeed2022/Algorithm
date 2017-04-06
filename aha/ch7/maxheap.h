#ifndef MAX_HEAP_H_
#define MAX_HEAP_H_
#include <algorithm>
#include <cstdio>
using namespace std;
namespace aha
{
   const int MAX_LEN = 101;
   int maxheap[MAX_LEN];
   int n = 0;
   void shiftdown(int maxheap[MAX_LEN], const int n, int i);
   int deletemax();
   int create_maxheap();

   void shiftdown(int maxheap[MAX_LEN], const int n, int i)
   {
      bool flag = false;
      int t;
      while (i * 2 <= n && !flag)
      {
         t = maxheap[i] < maxheap[i * 2] ? i * 2 : i;

         if (i * 2 + 1 <= n)
            t = maxheap[t] < maxheap[i * 2 + 1] ? i * 2 + 1 : t;
         if (t != i)
         {
            std::swap(maxheap[t], maxheap[i]);
            i = t;
         }
         else
            flag = true;
      }
   }
   int create_maxheap()
   {
      for (int i = n / 2; i >= 1; --i) 
         shiftdown(maxheap, n, i);
   }
   int deletemax()
   {
      int t      = maxheap[1];
      maxheap[1] = maxheap[n];
      n--;
      shiftdown(maxheap, n, 1);
      return t;
   }
}
#endif