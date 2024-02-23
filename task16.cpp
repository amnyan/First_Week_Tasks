#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class SortingStrategy {
public:
    virtual void sort(vector<int>& arr) const = 0;
    virtual ~SortingStrategy() {} 
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
private:
    ifstream inFile;
    ofstream outFile;

public:
    FileHandler(const string& inFileName, const string& outFileName) {
        inFile.open(inFileName);
        outFile.open(outFileName);
    }

    ~FileHandler() {
        if (inFile.is_open()) inFile.close();
        if (outFile.is_open()) outFile.close();
    }

    vector<int> readArrayFromFile() {
        vector<int> arr;
        if (inFile.is_open()) {
            int num;
            while (inFile >> num) {
                arr.push_back(num);
            }
        } else {
            cerr << "Unable to open input file." << endl;
        }
        return arr;
    }

    void saveArrayToFile(const vector<int>& arr) {
        if (outFile.is_open()) {
            for (int num : arr) {
                outFile << num << " ";
            }
        } else {
            cerr << "Unable to open output file." << endl;
        }
    }
};

class SortingApplication {
private:
    SortingStrategy* sortingStrategy;
    FileHandler fileHandler;

public:
    SortingApplication(const string& inFileName, const string& outFileName)
        : fileHandler(inFileName, outFileName), sortingStrategy(nullptr) {}

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
        int choice;
        cout << "Select sorting strategy:" << endl;
        cout << "0. Bubble Sort" << endl;
        cout << "1. Selection Sort" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        selectSortingStrategy(choice);

        vector<int> arr = fileHandler.readArrayFromFile();
        if (sortingStrategy) {
            sortingStrategy->sort(arr);
            fileHandler.saveArrayToFile(arr);
            cout << "Sorted array has been written to the output file." << endl;
        }
    }
};

int main() {
    string inputFileName, outputFileName;
    cout << "Enter the name of the input file: ";
    cin >> inputFileName;
    cout << "Enter the name of the output file: ";
    cin >> outputFileName;

    SortingApplication app(inputFileName, outputFileName);
    app.run();

    return 0;
}
