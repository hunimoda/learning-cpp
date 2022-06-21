#include <iostream>

namespace my_code {
  void foo() {
    std::cout << "foo() called in the my_code namespace" << std::endl;
  }
}

// using namespace my_code;
// be cautious in using 'using namespace <something>'
// it contaminates the namespace
// don't use using declaration in header file's global scope
// it forces all files to do so, too, to use it
using std::cout;

int main() {
  my_code::foo();
  // foo();
  cout << "using std::cout" << std::endl;
  return 0;
}