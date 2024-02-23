#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

enum SortingStrategy {
    BUBBLE_SORT,
    SELECTION_SORT
};

struct SortingOption {
    SortingStrategy strategy;
    void (*sortFunc)(vector<int>&);
};

void bubbleSort(vector<int>& arr);
void selectionSort(vector<int>& arr);

vector<int> readArrayFromFile(const string& fileName) {
    vector<int> arr;
    ifstream inFile(fileName);
    if (inFile.is_open()) {
        int num;
        while (inFile >> num) {
            arr.push_back(num);
        }
        inFile.close();
    } else {
        cerr << "Unable to open file: " << fileName << endl;
    }
    return arr;
}

void writeArrayToFile(const string& fileName, const vector<int>& arr) {
    ofstream outFile(fileName);
    if (outFile.is_open()) {
        for (size_t i = 0; i < arr.size(); ++i) {
            outFile << arr[i] << endl;
        }
        outFile.close();
        cout << "Sorted array has been written to file: " << fileName << endl;
    } else {
        cerr << "Unable to open file for writing: " << fileName << endl;
    }
}

void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        int minIdx = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        swap(arr[i], arr[minIdx]);
    }
}

int main() {
    SortingOption options[] = {
        {BUBBLE_SORT, bubbleSort},
        {SELECTION_SORT, selectionSort}
    };

    string fileName;
    cout << "Enter the name of the input file: ";
    cin >> fileName;

    vector<int> arr = readArrayFromFile(fileName);
    int choice;
    cout << "Select sorting strategy:" << endl;
    cout << "0. Bubble Sort" << endl;
    cout << "1. Selection Sort" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice < 0 || choice >= sizeof(options) / sizeof(options[0])) {
        cerr << "Invalid choice!" << endl;
        return 1;
    }


    options[choice].sortFunc(arr);

    writeArrayToFile("sorted_" + fileName, arr);

    return 0;
}
