#include <iostream>
#include <iomanip>

void SetBoolAlpha() {
  std::cout << std::boolalpha;
  std::cout << "Inside SetBoolAlpha(): " << true << std::endl;
  std::cout << std::noboolalpha;
}
int main() {
  std::cout << "Inside main(): " << true << std::endl;
  SetBoolAlpha();
  std::cout << "Inside main(): " << true << std::endl;

  std::cout.setf(std::ios::boolalpha);
  std::cout << "Inside main(): " << true << std::endl;
  std::cout.unsetf(std::ios::boolalpha);
  std::cout << "Inside main(): " << true << std::endl;

  // std::cout << "noboolalpha - default (10 == 10): " << (10 == 10) << std::endl;
  // std::cout << "noboolalpha - default (10 == 20): " << (10 == 20) << std::endl;

  // std::cout << "noboolalpha - default (true): " << true << std::endl;
  // std::cout << "noboolalpha - default (false): " << false << std::endl;
  
  // std::cout << std::boolalpha << std::endl;
  // std::cout << "boolalpha - default (10 == 10): " << (10 == 10) << std::endl;
  // std::cout << "boolalpha - default (10 == 20): " << (10 == 20) << std::endl;

  // std::cout << "boolalpha - default (true): " << true << std::endl;
  // std::cout << "boolalpha - default (false): " << false << std::endl;
  
  // std::cout << std::noboolalpha << std::endl;
  // std::cout << "noboolalpha - default (10 == 10): " << (10 == 10) << std::endl;
  // std::cout << "noboolalpha - default (10 == 20): " << (10 == 20) << std::endl;

  // std::cout << "noboolalpha - default (true): " << true << std::endl;
  // std::cout << "noboolalpha - default (false): " << false << std::endl;

  // std::cout << std::endl;
  // std::cout.setf(std::ios::boolalpha);
  // std::cout << "boolalpha - default (10 == 10): " << (10 == 10) << std::endl;
  // std::cout << "boolalpha - default (10 == 20): " << (10 == 20) << std::endl;

  // std::cout << "boolalpha - default (true): " << true << std::endl;
  // std::cout << "boolalpha - default (false): " << false << std::endl;

  // std::cout << std::resetiosflags(std::ios::boolalpha) << std::endl;
  // std::cout << "boolalpha - default (10 == 10): " << (10 == 10) << std::endl;
  // std::cout << "boolalpha - default (10 == 20): " << (10 == 20) << std::endl;

  // std::cout << "boolalpha - default (true): " << true << std::endl;
  // std::cout << "boolalpha - default (false): " << false << std::endl;
  return 0;
}