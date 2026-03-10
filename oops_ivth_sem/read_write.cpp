#include <iostream>
#include <fstream>
using namespace std;

int main() {
    
    // -------- Writing Part --------
    ofstream outFile("data.txt");

    if (!outFile) {
        cout << "Error creating file!";
        return 1;
    }

    outFile << "Hello Vaishnavi" << endl;
    outFile << "C++ File Handling" << endl;

    outFile.close();   // very important

    cout << "Data written successfully.\n\n";

    
    // -------- Reading Part --------
    ifstream inFile("data.txt");
    string line;

    if (!inFile) {
        cout << "Error opening file!";
        return 1;
    }

    cout << "Reading from file:\n";

    while (getline(inFile, line)) {
        cout << line << endl;
    }

    inFile.close();

    return 0;
}