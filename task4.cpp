#include <iostream>
float sum(float num1, float num2);
float sub(float num1, float num2);
float mul(float num1, float num2);
float div(float num1, float num2);

int main() {
    float num1 = 0;
    float num2 = 0;
    scanf("%f",&num1);
    scanf("%f",&num2);
    std::cout << "The sum is "<< sum(num1,num2) << std::endl;
    std::cout << "The sub is "<< sub(num1,num2) << std::endl;
    std::cout << "The mul is "<< mul(num1,num2) << std::endl;
    std::cout << "The div is "<< div(num1,num2) << std::endl;
}

float sum(float num1, float num2) {
    return num1 + num2;
}

float sub(float num1, float num2) {
    return num1 - num2;
}

float mul(float num1, float num2) {
    return num1 * num2;
}

float div(float num1, float num2) {
    if (num2 == 0) {
        return -1;
    }
    return num1 / num2;
}