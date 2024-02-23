#include <iostream>
#include <cmath>
#include <stdexcept>

class Shape {
public:
    virtual double calculateArea() const = 0;
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {
        if (radius <= 0) {
            throw std::invalid_argument("Radius must be positive");
        }
    }

    double calculateArea() const override {
        return M_PI * radius * radius;
    }
};

class Rectangle : public Shape {
private:
    double width;
    double height;

public:
    Rectangle(double w, double h) : width(w), height(h) {
        if (width <= 0 || height <= 0) {
            throw std::invalid_argument("Width and height must be positive");
        }
    }

    double calculateArea() const override {
        return width * height;
    }
};

int main() {
    try {
        Circle circle(-25); 
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error creating circle: " << e.what() << std::endl;
    }

    try {
        Rectangle rectangle(4, 3); 
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error creating rectangle: " << e.what() << std::endl;
    }

    return 0;
}
