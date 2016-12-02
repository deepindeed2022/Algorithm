// bad_exception example
#include <iostream>       // std::cerr
#include <exception>      // std::bad_exception, std::set_unexpected
#include <cstdlib>

void myunexpected(){
  std::cerr << "unexpected handler called at:" << std::endl;
  throw;
}

void myfunction() throw(int, std::bad_exception) {
  throw 'x'; // throws char (not in exception-specification)
}
void myterminate()
{
    std::set_terminate(myterminate);
    throw 0;
    std::cerr << "terminate handler called\n";
}
int main (void) {
    std::set_unexpected(myunexpected);
    try 
    {
        myfunction();
    }
    catch (int) 
    { 
        std::cerr << "caught int\n"; 
    }
    catch (std::bad_exception be) 
    { 
        std::cerr << "caught bad_exception\n"; 
    }
    catch (...) 
    { 
        std::cerr << "caught some other exception\n"; 
    }

    return 0;
}