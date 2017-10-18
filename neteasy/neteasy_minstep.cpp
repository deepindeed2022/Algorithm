#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
   int N, M;
   while (cin >> N >> M)
   {
      vector<int> steps(M + 1, INT_MAX);
      steps[N] = 0;
      for (int i = N; i <= M; i++)
      {
         if (steps[i] == INT_MAX)
         {
            continue;
         }

         for (int j = 2; (j * j) <= i; j++)
         {
            if (i % j == 0)
            {
               if (i + j <= M)
               {
                  steps[i + j] = min(steps[i] + 1, steps[i + j]);
               }
               if (i + (i / j) <= M)
               {
                  steps[i + (i / j)] = min(steps[i] + 1, steps[i + (i / j)]);
               }
            }
         }
      }
      if (steps[M] == INT_MAX)
      {
         steps[M] = -1;
      }
      cout << steps[M] << endl;
   }
   return 0;
}