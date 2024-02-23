#include <iostream>
#include <vector>
#include <algorithm>

// Enum for sorting strategies
enum class SortingStrategy {
    BUBBLE_SORT,
    SELECTION_SORT
};

// Struct to represent a sorting option
struct SortingOption {
    SortingStrategy strategy;
    void (*sort)(std::vector<int>&);
};

// Sorting function prototypes
void bubble_sort(std::vector<int>& arr);
void selection_sort(std::vector<int>& arr);

// Sorting functions
void bubble_sort(std::vector<int>& arr) {
    // Implementation of Bubble Sort
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void selection_sort(std::vector<int>& arr) {
    // Implementation of Selection Sort
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        int min_index = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        std::swap(arr[i], arr[min_index]);
    }
}

int main() {
    // Array of sorting options
    SortingOption sortingOptions[] = {
        {SortingStrategy::BUBBLE_SORT, bubble_sort},
        {SortingStrategy::SELECTION_SORT, selection_sort}
    };

    std::vector<int> arr;

    arr.push_back(5);
    arr.push_back(2);
    arr.push_back(8);
    arr.push_back(1);
    arr.push_back(3);

    // Prompt user to select sorting algorithm
    std::cout << "Select a sorting algorithm:" << std::endl;
    std::cout << "1. Bubble Sort" << std::endl;
    std::cout << "2. Selection Sort" << std::endl;

    int choice;
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    if (choice < 1 || choice > 2) {
        std::cout << "Invalid choice." << std::endl;
        return 1;
    }

    SortingStrategy selectedStrategy;
    if (choice == 1) {
        selectedStrategy = SortingStrategy::BUBBLE_SORT;
    } else {
        selectedStrategy = SortingStrategy::SELECTION_SORT;
    }

    // Find selected sorting option
    SortingOption selectedOption;
    for (size_t i = 0; i < sizeof(sortingOptions) / sizeof(sortingOptions[0]); ++i) {
        const SortingOption& option = sortingOptions[i];
        if (option.strategy == selectedStrategy) {
            selectedOption = option;
            break;
        }
    }

    // Perform sorting using selected strategy
    selectedOption.sort(arr);

    // Print sorted array
    std::cout << "Sorted array:" << std::endl;
    for (int num; num < arr.size(); num++) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
