#include <iostream>

int Max(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}


int Min(int arr[], int size) {
    int min = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

double Average(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += arr[i];
    }
    return (double)(sum) / size;
}

int main() {
    int numbers[] = {10, 5, 8, 15, 20};

    int max = Max(numbers, 5);
    int min = Min(numbers, 5);
    double average = Average(numbers, 5);

    std::cout << "Maximum value in the array: " << max << std::endl;
    std::cout << "Minimum value in the array: " << min << std::endl;
    std::cout << "Average value of the array: " << average << std::endl;


    return 0;
}
