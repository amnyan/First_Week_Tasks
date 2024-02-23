#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class SortingStrategy {
public:
    virtual void sort(vector<int>& arr) const = 0;
};

class BubbleSort : public SortingStrategy {
public:
    void sort(vector<int>& arr) const override {
        int n = arr.size();
        for (int i = 0; i < n - 1; ++i) {
            for (int j = 0; j < n - i - 1; ++j) {
                if (arr[j] > arr[j + 1]) {
                    swap(arr[j], arr[j + 1]);
                }
            }
        }
    }
};

class SelectionSort : public SortingStrategy {
public:
    void sort(vector<int>& arr) const override {
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
};

class FileHandler {
public:
    vector<int> readArrayFromFile(const string& fileName) const {
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

    void saveArrayToFile(const string& fileName, const vector<int>& arr) const {
        ofstream outFile(fileName);
        if (outFile.is_open()) {
            for (int num : arr) {
                outFile << num << " ";
            }
            outFile.close();
            cout << "Sorted array has been written to file: " << fileName << endl;
        } else {
            cerr << "Unable to open file for writing: " << fileName << endl;
        }
    }
};

class SortingApplication {
private:
    SortingStrategy* sortingStrategy;
    FileHandler fileHandler;

public:
    SortingApplication() : sortingStrategy(nullptr) {}

    ~SortingApplication() {
        delete sortingStrategy;
    }

    void selectSortingStrategy(int choice) {
        if (sortingStrategy)
            delete sortingStrategy;

        switch(choice) {
            case 0:
                sortingStrategy = new BubbleSort();
                break;
            case 1:
                sortingStrategy = new SelectionSort();
                break;
            default:
                cerr << "Invalid choice!" << endl;
        }
    }

    void run() {
        string inputFileName, outputFileName;
        cout << "Enter the name of the input file: ";
        cin >> inputFileName;

        cout << "Enter the name of the output file: ";
        cin >> outputFileName;

        int choice;
        cout << "Select sorting strategy:" << endl;
        cout << "0. Bubble Sort" << endl;
        cout << "1. Selection Sort" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        selectSortingStrategy(choice);

        vector<int> arr = fileHandler.readArrayFromFile(inputFileName);
        if (sortingStrategy) {
            sortingStrategy->sort(arr);
            fileHandler.saveArrayToFile(outputFileName, arr);
        }
    }
};

int main() {
    SortingApplication app;
    app.run();
    return 0;
}
