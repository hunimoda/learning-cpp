#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

double calc_cost(double base_cost, double tax_rate = 0.06, double shipping = 3.50);
void greeting(string name, string prefix = "Mr.", string suffix = "");

int main() {
    double cost {};

    cout << fixed << setprecision(2);

    cost = calc_cost(100.0, 0.08, 4.25);
    cout << "Cost is: " << cost << endl;

    cost = calc_cost(100.0, 0.08);
    cout << "Cost is: " << cost << endl;

    cost = calc_cost(200.0);
    cout << "Cost is: " << cost << endl;

    greeting("Daehoon Kim", "Dr.", "M.D.");
    greeting("Doyoon Kim", "Prof.", "Ph.D.");
    greeting("Frank Miller", "Dr.");
    greeting("William Smith");

    cout << endl;

    return 0;
}

double calc_cost(double base_cost, double tax_rate, double shipping) {
    return base_cost * (1 + tax_rate) + shipping;
}

void greeting(string name, string prefix, string suffix) {
    cout << "Hello, " << prefix << " " << name 
        << " " << suffix << endl;
}