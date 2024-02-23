#include <iostream>

using namespace std;

class Shape {
public:
    virtual double calculateArea() const = 0;
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}
    double calculateArea() const override {
        return 3.14159 * radius * radius;
    }
};

class Rectangle : public Shape {
private:
    double width;
    double height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}
    double calculateArea() const override {
        return width * height;
    }
};

int main() {
    Circle circle(10);
    Rectangle rectangle(3, 9);


    cout << "Area of the circle: " << circle.calculateArea() << endl;
    cout << "Area of the rectangle: " << rectangle.calculateArea() << endl;

    return 0;
}
