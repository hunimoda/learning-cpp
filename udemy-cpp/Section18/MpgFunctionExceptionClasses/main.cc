#include <iostream>

class DivideByZeroException {};
class NegativeValueException {};

double CalculateMpg(int miles, int gallons) {
  if (!gallons)
    throw DivideByZeroException();
  if (miles < 0 || gallons < 0)
    throw NegativeValueException();
  return static_cast<double>(miles) / gallons;
}

int main() {
  int miles, gallons;
  std::cout << "Enter the miles driven: ";
  std::cin >> miles;
  std::cout << "Enter the gallons used: ";
  std::cin >> gallons;

  try {
    double miles_per_gallon = CalculateMpg(miles, gallons);
    std::cout << "Result: " << miles_per_gallon << std::endl;
  } catch (const DivideByZeroException &e) {
    std::cerr << "Sorry, you can't divide by zero" << std::endl;
  } catch (const NegativeValueException &e) {
    std::cerr << "Sorry, one of your parameters is negative" << std::endl;
  }
  std::cout << "Bye" << std::endl;
  return 0;
}