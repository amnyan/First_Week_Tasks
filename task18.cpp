#include <iostream>

template<typename T>
class Shape {
public:
    virtual T calculateArea() const = 0;
};


template<typename T>
class Circle : public Shape<T> {
private:
    T radius;

public:
    Circle(T r) : radius(r) {}

    T calculateArea() const override {
        return 3.14159 * radius * radius;
    }
};


template<typename T>
class Rectangle : public Shape<T> {
private:
    T width;
    T height;

public:
    Rectangle(T w, T h) : width(w), height(h) {}

    T calculateArea() const override {
        return width * height;
    }
};

int main() {
    Circle<int> circleInt(5);
    Rectangle<int> rectangleInt(4, 6);
    std::cout << "Circle area (int): " << circleInt.calculateArea() << std::endl;
    std::cout << "Rectangle area (int): " << rectangleInt.calculateArea() << std::endl;

    Circle<float> circleFloat(5.0f);
    Rectangle<float> rectangleFloat(4.0f, 6.0f);
    std::cout << "Circle area (float): " << circleFloat.calculateArea() << std::endl;
    std::cout << "Rectangle area (float): " << rectangleFloat.calculateArea() << std::endl;

    Circle<double> circleDouble(5.0);
    Rectangle<double> rectangleDouble(4.0, 6.0);
    std::cout << "Circle area (double): " << circleDouble.calculateArea() << std::endl;
    std::cout << "Rectangle area (double): " << rectangleDouble.calculateArea() << std::endl;

    return 0;
}
