#include <iostream>
using namespace std;
#include <vector>

std::vector<std::vector<bool> >* paint;
static int totlenum = 0;
static int sum = 0;
int n, m;
bool isPlace(int i, int j)
{
  return ((i < n) && (j < m) && (*paint)[i][j]);
}
void backtrack(int x, int y, int step)
{
  if(step > sum) totlenum++;
  if(isPlace(x+1,y)) 
    backtrack(x+1, y, step + 1);
  if(isPlace(x,y+1)) 
    backtrack(x, y+1, step + 1);

}
int main(int argc, char const *argv[])
{
  int N;
  
  int k;
  int x, y;
  cin >> N;
  while(N--)
  {
      cin >> n>> m;
      cin >> k;


      totlenum = 0;
      paint = new std::vector<std::vector<bool> >(n, std::vector< bool>(m, true));
      std::cout << "ok";
      for (int i = 0; i < k; ++i)
      {
          cin >> x >> y;
        x = 1, y =3;
          (*paint)[x][y] = false;
      }
      sum = m + n;
      backtrack(0, 0, 1);
      std::cout <<totlenum<<std::endl;
      delete paint;
  }

  return 0;
}

