#include <iostream>

using namespace std;

const double kMathPi {3.141592};

// Function prototypes
double calc_area_circle(double radius);
void area_circle();
double calc_volume_cylinder(double radius, double height);
void volume_cylinder();

int main() {

    area_circle();
    volume_cylinder();

    return 0;
    
}

double calc_area_circle(double radius) {
    return kMathPi * radius * radius;   // pi * r^2
}

void area_circle() {
    double radius {};

    cout << "Enter radius: ";
    cin >> radius;

    cout << "Area of circle: " << calc_area_circle(radius) << endl;
}

double calc_volume_cylinder(double radius, double height) {
    return calc_area_circle(radius) * height;
}

void volume_cylinder() {
    double radius {};
    double height {};

    cout << "Enter radius: ";
    cin >> radius;
    cout << "Enter height: ";
    cin >> height;

    cout << "Volume of cylinder: " 
        << calc_volume_cylinder(radius, height) << endl;
}
