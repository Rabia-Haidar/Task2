#include <iostream>
#include <conio.h>
#include <chrono>    
#include <iomanip> 
using namespace std;
using namespace chrono;

class Circle {
    double radius;

public:
    Circle() : radius(0) {}

    void set_radius(double r) {
        radius = r;
    }

    double get_radius() {
        return radius;
    }

    Circle operator+(Circle & other) {
        Circle temp;
        temp.radius = radius + other.radius;
        return temp;
    }
};

int main() {
    Circle c1, c2, c3;

    double r1;
    double r2;
    cout << "Enter radius for Circle 1: ";
    cin >> r1;
    c1.set_radius(r1);

    cout << "Enter radius for Circle 2: ";
    cin >> r2;
    c2.set_radius(r2);

    c3 = c1 + c2;

    cout << "Radius of Circle 3 is " << c3.get_radius() << endl;

    cout << "Press any key to continue...";
    _getch();

    return 0;
}

class Complex {
    double real;
    double imaginary;

public:
    Complex() : real(0), imaginary(0) {}

    friend istream& operator>>(istream& input, Complex& c) {
        cout << "Enter real part: ";
        input >> c.real;
        cout << "Enter imaginary part: ";
        input >> c.imaginary;
        return input;
    }

    friend ostream& operator<<(ostream& output, Complex& c) {
        output << c.real << " + " << c.imaginary << "i";
        return output;
    }
};

int main() {
    auto start = high_resolution_clock::now();
    Complex com1;
    cin >> com1;
    cout << "The complex number is: " << com1 << endl;

    auto end = high_resolution_clock::now();
    chrono::duration<double> time = end - start; 
    cout << "Process exited after " << fixed << setprecision(3) << time.count() << " seconds with return value 0."<<endl;
    cout<<"Press any key to continue..."<<endl;
    _getch();

    return 0;
}
