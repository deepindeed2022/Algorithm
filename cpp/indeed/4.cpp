#include <iostream>
//#include <fstream>
#include <assert.h>
#include <malloc.h>
#include <math.h>

using namespace std;
int main(int argc, char const *argv[]) {

   int N, A, B;
   // ifstream cin("monster.txt");
   std::cin >> N >> A >> B;
   int *arr = NULL;

   long long sum = 0;
   int k;
   int res = -1;
   arr = (int *)malloc((N) * sizeof(int));
   assert(arr != NULL);

   for (int i = 0; i < N; i++) {
      cin >> arr[i];
   }

   for (int i = 0; i < N; i++)
      sum += arr[i];
   k = ceil((sum - (B - A)) / (float)A);

   if (k <= 0)
      std::cout << res << std::endl;
   else
      std::cout << k << std::endl;

   free(arr);
   arr = NULL;

   return 0;
}