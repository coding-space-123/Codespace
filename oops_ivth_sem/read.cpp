#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream file("data.txt");   // open in read mode
    string line;

    if (!file) {
        cout << "File not found!";
        return 1;
    }

    while (getline(file, line)) {
        cout << line << endl;
    }

    file.close();
    return 0;
}