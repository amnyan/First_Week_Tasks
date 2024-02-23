#include <iostream>


void bubble_sort(int* arr, int size) {
    for(size_t i = 0; i < size - 1; ++i) {
        for(size_t j = 0; j < size - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}

void selection_sort(int* arr, int size) {
    for(size_t j = 0; j < size - 1 ; ++j) {
        int min = j;
        for(size_t i = j + 1; i < size ; ++i) {
            if(arr[min] > arr[i]) {
                min = i;
            }
        }
        int tmp = arr[j];
        arr[j] = arr[min];
        arr[min] = tmp;
    }
}

int main() {
    int const size = 10;
    int arr[size] = {8,9,2,5,1,0,3,6,7,4};
    for(size_t i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    //bubble_sort(arr, size);
    selection_sort(arr,size);
    for(size_t i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}