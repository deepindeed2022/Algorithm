#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
void test()
{
    int i;
    std::vector<int> iv(2, 9);
    std::cout << "size="<<iv.size() << std::endl;
    std::cout << "capacity="<<iv.capacity()<<std::endl;
    
    iv.push_back(1);
    std::cout << "size="<<iv.size() << std::endl;
    std::cout << "capacity="<<iv.capacity()<<std::endl;
    
    iv.push_back(2);
    std::cout << "size="<<iv.size() << std::endl;
    std::cout << "capacity="<<iv.capacity()<<std::endl;
    
    iv.push_back(3);
    std::cout << "size="<<iv.size() << std::endl;
    std::cout << "capacity="<<iv.capacity()<<std::endl;
    
    iv.push_back(4);
    std::cout << "size="<<iv.size() << std::endl;
    std::cout << "capacity="<<iv.capacity()<<std::endl;

    for(size_t i = 0; i< iv.size(); i++)
    {
        std::cout << iv[i] << " ";
    }
    std::cout << std::endl;

    iv.push_back(5);
    std::cout << "size="<<iv.size() << std::endl;
    std::cout << "capacity="<<iv.capacity()<<std::endl;

    for(size_t i = 0; i< iv.size(); i++)
    {
        std::cout << iv[i] << " ";
    }
    std::cout << std::endl;

    iv.pop_back();
    iv.pop_back();
    std::cout << "size="<<iv.size() << std::endl;
    std::cout << "capacity="<<iv.capacity()<<std::endl;

    iv.pop_back();
    std::cout << "size="<<iv.size() << std::endl;
    std::cout << "capacity="<<iv.capacity()<<std::endl;

    std::vector<int>::iterator ivite = find(iv.begin(), iv.end(),1);
    if(ivite != iv.end()) iv.erase(ivite);

    std::cout << "size="<<iv.size() << std::endl;
    std::cout << "capacity="<<iv.capacity()<<std::endl;
    iv.shrink_to_fit();
    std::cout << "size="<<iv.size() << std::endl;
    std::cout << "capacity="<<iv.capacity()<<std::endl;
    for(size_t i = 0; i< iv.size(); i++)
    {
        std::cout << iv[i] << " ";
    }
    std::cout << std::endl;

    ivite = find(iv.begin(), iv.end(),2);
    if(ivite != iv.end()) iv.insert(ivite, 3,7);

    std::cout << "size="<<iv.size() << std::endl;
    std::cout << "capacity="<<iv.capacity()<<std::endl;

    for(size_t i = 0; i< iv.size(); i++)
    {
        std::cout << iv[i] << " ";
    }
    std::cout << std::endl;

    iv.clear();
    std::cout << "size="<<iv.size() << std::endl;
    std::cout << "capacity="<<iv.capacity()<<std::endl;
}
int main(int argc, char const *argv[])
{
    test();
    return 0;
}