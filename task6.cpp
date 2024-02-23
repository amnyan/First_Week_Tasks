#include <iostream>

int main() {
    int number = 13;
    int *ptr = &number;
    int &rf = number;
    std::cout << "Number is  variable: " << number << std::endl;

    *ptr = 24;
    std::cout << "Number in 2nd step: " << number << std::endl;

    rf = 50;
    std::cout << "Number in 3th step: " << number << std::endl;

}