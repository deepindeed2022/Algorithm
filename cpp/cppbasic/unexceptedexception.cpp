// bad_exception example
#include <cstdlib>
#include <exception> // std::bad_exception, std::set_unexpected
#include <iostream>  // std::cerr

void myunexpected() {
  std::cerr << "unexpected handler called at:" << __FUNCTION__ << std::endl;
  throw;
}

// 后面throw声明可能抛出的异常类型
void myfunction() throw(int, std::bad_exception) {
  throw 'x'; // throws char (not in exception-specification)
}
void myterminate() {
  std::set_terminate(myterminate);
  throw 0;
  std::cerr << "terminate handler called\n";
}
int main(void) {
  std::set_unexpected(myunexpected);
  try {
    myterminate();
  } catch (int) {
    std::cerr << "caught int\n";
  } catch (std::bad_exception be) {
    std::cerr << "caught bad_exception\n";
  } catch (...) {
    std::cerr << "caught some other exception\n";
  }

  return 0;
}