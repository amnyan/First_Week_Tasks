#include <iostream>

using namespace std;

class Shape {
public:
    virtual double calculateArea() const {
        return 0.0;
    }
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

void printArea(const Shape* shapePtr) {
    cout << "Area: " << shapePtr->calculateArea() << endl;
}

int main() {
    Circle circle(5.0);
    Rectangle rectangle(4.0, 6.0);

    printArea(&circle);
    printArea(&rectangle);

    return 0;
}
