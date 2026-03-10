#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream file("data.dat");   // open file in write mode

    if (!file) {
        cout << "File not created!";
        return 1;
    }

    file << "Hello..... Vaishnavi" << endl;
    file << "C++ file handling is simple." << endl;

    file.close();   // close file

    cout << "Data written successfully.";
    return 0;
}