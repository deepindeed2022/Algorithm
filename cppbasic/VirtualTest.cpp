#include <iostream>
using namespace std;
class Base1 {
public:
            virtual void f() { cout << "Base1::f" << endl; }
            virtual void g() { cout << "Base1::g" << endl; }
            virtual void h() { cout << "Base1::h" << endl; }
            ~Base1(){cout << "Base1::~Base1()\n";}
};
class Base2 {
public:
            virtual void f() { cout << "Base2::f" << endl; }
            virtual void g() { cout << "Base2::g" << endl; }
            virtual void h() { cout << "Base2::h" << endl; }
            ~Base2(){cout << "Base2::~Base2()\n";}


};
class Base3 {
public:
            virtual void f() { cout << "Base3::f" << endl; }
            virtual void g() { cout << "Base3::g" << endl; }
            virtual void h() { cout << "Base3::h" << endl; }
            virtual void i() { cout << "Base3::i" << endl; }
            ~Base3(){cout << "Base3::~Base3()\n";}

};
class Derive : public Base1, public Base2, public Base3 {
public:
            virtual void f() { cout << "Derive::f" << endl; }
            virtual void g1() { cout << "Derive::g1" << endl; }
            ~Derive(){cout << "Base1::~Base1()\n";}
};
typedef void(*Fun)(void);
void Base_vTable()
{

            Fun pFun = NULL;
            Base1 d;
            int** pVtab = (int**)&d;
           //Base1's vtable
            //pFun = (Fun)*((int*)*((int*)((int*)&d+0))+0);
            pFun = (Fun)pVtab[0][0];
            pFun();
            //pFun = (Fun)*((int*)*((int*)((int*)&d+0))+1);
            pFun = (Fun)pVtab[0][1];
            pFun();
            //pFun = (Fun)*((int*)*(int*)((int*)&d+0)+2);
            pFun = (Fun)pVtab[0][2];
            pFun();
            //Derive's vtable
            std::cout << pFun << std::endl;
           
}

void Derive_vTable()
{

            Fun pFun = NULL;
            Derive d;
            int** pVtab = (int**)&d;
           //Base1's vtable
            //pFun = (Fun)*((int*)*((int*)((int*)&d+0))+0);
            pFun = (Fun)pVtab[0][0];
            pFun();
            //pFun = (Fun)*((int*)*((int*)((int*)&d+0))+1);
            pFun = (Fun)pVtab[0][1];
            pFun();
            //pFun = (Fun)*((int*)*(int*)((int*)&d+0)+2);
            pFun = (Fun)pVtab[0][2];
            pFun();
            //Derive's vtable
            //pFun = (Fun)*((int*)*(int*)((int*)&d+0)+3);
            pFun = (Fun)pVtab[0][3];
            pFun();
            //The tail of the vtable
            pFun = (Fun)pVtab[0][4];
            cout<<pFun <<  "-----------" <<&pFun<<endl;

            //Base2's vtable
            //pFun = (Fun)*((int*)*(int*)((int*)&d+1)+0);
            pFun = (Fun)pVtab[1][0];
            pFun();
            //pFun = (Fun)*((int*)*(int*)((int*)&d+1)+1);

            pFun = (Fun)pVtab[1][1];
            pFun();
            pFun = (Fun)pVtab[1][2];
            pFun();
            //The tail of the vtable
            pFun = (Fun)pVtab[1][3];

            cout<<pFun<<endl;
            //Base3's vtable
            //pFun = (Fun)*((int*)*(int*)((int*)&d+1)+0);
            pFun = (Fun)pVtab[2][0];
            pFun();
            //pFun = (Fun)*((int*)*(int*)((int*)&d+1)+1);
            pFun = (Fun)pVtab[2][1];
            pFun();
            pFun = (Fun)pVtab[2][2];
            pFun();
            pFun = (Fun)pVtab[2][3];
            pFun();
            //The tail of the vtable
            pFun = (Fun)pVtab[2][4];
            //pFun();
            cout<<pFun<<endl;
}
int main(int argc, char const *argv[])
{
      // Derive_vTable();
      Base_vTable();
      return 0;
}