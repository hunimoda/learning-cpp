#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

struct City {
  std::string name;
  long int population;
  double cost;
};

struct Country {
  std::string name;
  std::vector<City> cities;
};

struct Tours {
  std::string title;
  std::vector<Country> countries;
};

void DrawHorizontalLine(char c) {
  std::cout << std::setw(70) << std::setfill(c) << ""
            << std::setfill(' ') << std::endl;
}

int main() {
  Tours tours = {
    "Tour Ticket Prices from Miami", {
      {
        "Colombia", {
          { "Bogota",    8'778'000, 400.98 },
          { "Cali",      2'401'000, 424.12 },
          { "Medellin",  2'464'000, 350.98 },
          { "Cartagena", 972'000,   345.34 },
        }
      }, {
        "Brazil", {
          { "Rio De Janiero", 13'500'000, 567.45 },
          { "Sao Paulo",      11'310'000, 975.45 },
          { "Salvador",       18'234'000, 855.99 },
        }
      }, {
        "Chile", {
          { "Valdivia", 260'000,   569.12 },
          { "Santiago", 7'040'000, 520.00 },
        }
      }, {
        "Argentina", {
          { "Buenos Aires", 3'010'000, 723.77 },
        }
      }
    }
  };

  std::cout << std::endl << std::endl;
  DrawHorizontalLine('=');
  std::cout << std::setw(50) << tours.title << std::endl << std::endl;
  DrawHorizontalLine('=');

  std::cout << std::setw(20) << std::left << "Country";
  std::cout << std::setw(25) << std::left << "City";
  std::cout << std::setw(10) << std::right << "Population";
  std::cout << std::setw(15) << std::right << "Price" << std::endl;
  DrawHorizontalLine('-');

  for (const Country &country : tours.countries) {
    bool is_first_row = true;
    for (const City &city : country.cities) {
      std::cout << std::setw(20) << std::left
                << (is_first_row ? country.name : "");
      std::cout << std::setw(25) << std::left << city.name;
      std::cout << std::setw(10) << std::right << city.population;
      std::cout << std::setw(15) << std::right << std::setprecision(2)
                << std::fixed << city.cost << std::endl;
      is_first_row = false;
    }
  }
  DrawHorizontalLine('=');

  std::cout << std::endl << std::endl;
  return 0;
}