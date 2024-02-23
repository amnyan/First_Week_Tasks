#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

void writeNamesToFile(const string& fileName, const vector<string>& names) {
    ofstream outFile(fileName);
    if (outFile.is_open()) {
        for (size_t i = 0; i < names.size(); ++i) {
            outFile << names[i] << endl;
        }

        cout << " written to the file successfully!" << endl;
        outFile.close();
    } else {
        cerr << "error for writing: " << fileName << endl;
    }
}

void readNamesFromFile(const string& fileName) {
    ifstream inFile(fileName);
    if (inFile.is_open()) {
        cout << "Names from the file:" << endl;
        string name;
        while (getline(inFile, name)) {
            cout << name << endl;
        }
        inFile.close();
    } else {
        cerr << "error: " << fileName << endl;
    }
}

int main() {
    const string fileName = "names.txt";
    vector<string> names;
    names.push_back("Arman");
    names.push_back("Hasmik");
    names.push_back("Narek");
    names.push_back("David");
    names.push_back("Lida");
    writeNamesToFile(fileName, names);

    readNamesFromFile(fileName);

    return 0;
}
