#include <iostream>
#include <iomanip>

int main() {
  int num = 255;
  
  std::cout << "\n---------------------------------------------" << std::endl;
  std::cout << "\tstd::dec - " << std::dec << num << std::endl;
  std::cout << "\tstd::hex - " << std::hex << num << std::endl;
  std::cout << "\tstd::oct - " << std::oct << num << std::endl;

  std::cout << "\n---------------------------------------------" << std::endl;
  std::cout << std::showbase;
  std::cout << "\tstd::dec - " << std::dec << num << std::endl;
  std::cout << "\tstd::hex - " << std::hex << num << std::endl;
  std::cout << "\tstd::oct - " << std::oct << num << std::endl;

  std::cout << "\n---------------------------------------------" << std::endl;
  std::cout << std::uppercase;
  std::cout << "\tstd::dec - " << std::dec << num << std::endl;
  std::cout << "\tstd::hex - " << std::hex << num << std::endl;
  std::cout << "\tstd::oct - " << std::oct << num << std::endl;

  std::cout << "\n---------------------------------------------" << std::endl;
  std::cout << std::showpos;
  std::cout << "\tstd::dec - " << std::dec << num << std::endl;
  std::cout << "\tstd::hex - " << std::hex << num << std::endl;
  std::cout << "\tstd::oct - " << std::oct << num << std::endl;

  std::cout.setf(std::ios::showbase);
  std::cout.setf(std::ios::uppercase);
  std::cout.setf(std::ios::showpos);

  std::cout << "\n---------------------------------------------" << std::endl;
  std::cout << "\tstd::dec - " << std::dec << num << std::endl;
  std::cout << "\tstd::hex - " << std::hex << num << std::endl;
  std::cout << "\tstd::oct - " << std::oct << num << std::endl;

  std::cout << std::resetiosflags(std::ios::basefield);
  std::cout << std::resetiosflags(std::ios::showbase);
  std::cout << std::resetiosflags(std::ios::showpos);
  std::cout << std::resetiosflags(std::ios::uppercase);

  std::cout << "\n---------------------------------------------" << std::endl;
  std::cout << "Enter an integer: ";
  std::cin >> num;

  std::cout << "Decimal default: " << num << std::endl;

  std::cout << std::hex;
  std::cout << "Hexadecimal    : " << num << std::endl;
  std::cout << "Hexadecimal    : " << std::uppercase << num << std::endl;
  std::cout << "Hexadecimal    : " << std::nouppercase << num << std::endl;

  std::cout << std::oct;
  std::cout << "Octal          : " << num << std::endl;
  return 0;
}