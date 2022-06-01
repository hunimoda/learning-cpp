#include <iostream>
#include <string>

double CalculateMpg(int miles, int gallons) {
  if (!gallons)
    throw 0;
  if (miles < 0 || gallons < 0)
    throw std::string("Negative value error");
  return static_cast<double>(miles) / gallons;
}

int main() {
  int miles, gallons;
  double miles_per_gallon;

  std::cout << "Enter the miles: ";
  std::cin >> miles;
  std::cout << "Enter the gallons: ";
  std::cin >> gallons;

  try {
    miles_per_gallon = CalculateMpg(miles, gallons);
    std::cout << "Result: " << miles_per_gallon << std::endl;
  } catch (int &e) {
    std::cerr << "Caught exception: " << e << std::endl;
  } catch (std::string &e) {
    std::cerr << "Caught string exception: " << e << std::endl;
  } catch (...) {
    std::cerr << "Catch all handler" << std::endl;
  }
  std::cout << "Bye" << std::endl;

  return 0;
}