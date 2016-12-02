#include <iostream>
#include <typeinfo>
using namespace std;
class CComplexObject // a demo class
{
public:
     void clone() { cout << "in clone" << endl; }
};
struct __true_type 
{
};

struct __false_type 
{
};
// Solving the problem of choosing method to call by inner traits class
template <typename T, bool isClonable>
class XContainer
{
public:
     enum {Clonable = isClonable};

     void clone(T* pObj)
     {
         Traits<isClonable>().cloneable();
     }

    template <bool flag>
    class Traits
    {
    };

    template <> 
    class Traits<true>  {
        typedef __true_type cloneable;
        public:
            void clone(T* pObj)
            {
                std::cout << "Before Cloning Clonable type" << std::endl;
                pObj->clone();
                std::cout << "After Cloning Clonable type" << std::endl;
            }
    };
    template <> 
    class Traits<false>{
        typedef __false_type cloneable;
        public:
            void clone(T* pObj)
            {
                std::cout << "Cloning non Clonable type" <<std::endl;
            }
    };
};

int main(int argc, char const *argv[])
{
     int* p1 = 0;
     CComplexObject* p2 = 0;

     XContainer<int, false> n1;
     XContainer<CComplexObject, true> n2;
    return 0;
}
