//Develop a program that asks the user for a number and then, using if-else statements, checks whether the number is positive, 
//negative, or zero. Extend the program with a switch-case to assign a grade (A, B, C, D, F) based on a number range (e.g., 90-100 for A).
// Lastly, implement a loop that prints numbers from 1 to 10. This task teaches the fundamental control structures for program flow. | 

#include <iostream>


int main() {
    int user_num = 0;
    std::cout << "Please enter the number : ";
    std::cin >> user_num;
    if (user_num > 0) {
        std::cout << "The number is positive" << std::endl;
    } else if (user_num < 0) {
        std::cout << "The number is negative" << std::endl;
    } else {
        std::cout << "The number is Zero" << std::endl;
    }

    switch (user_num)
    {
    case 90 ... 100:
        std::cout << "The Value is A" << std::endl;
        break;
    case 80 ... 89:
        std::cout << "The Value is B" << std::endl;
        break;
    case 70 ... 79:
        std::cout << "The Value is C" << std::endl;
        break;
    case 60 ... 69:
        std::cout << "The Value is D" << std::endl;
        break;
    case 0 ... 59:
        std::cout << "The Value is F" << std::endl;
        break;
    default:
        std::cout << "The number is out of range" << std::endl;
        break;
    }

    for(size_t i = 1; i <= 10; ++i) {
        std::cout << i << " ";
    }
    std::cout << std:: endl;
    return 0;
}