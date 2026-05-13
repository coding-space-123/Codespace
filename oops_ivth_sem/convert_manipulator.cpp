#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream fout("output.txt");
    if (!fout) {
        cout << "File cannot be opened!";
        return 0;
    }

    cout << "Writing characters at different positions:\n";

    // Write first 5 characters
    fout << "HELLO";
    cout << "Current write position (tellp): " << fout.tellp() << endl;

    // Move write pointer to beginning and overwrite
    fout.seekp(0, ios::beg);
    fout << "h";  // overwrite 'H'
    cout << "Write position after seekp to beginning: " << fout.tellp() << endl;

    // Move write pointer 3 characters ahead
    fout.seekp(2, ios::beg);
    fout << "X";  // overwrites 'L'
    cout << "Write position after seekp to 4th char: " << fout.tellp() << endl;

    
    fout.close();
    ifstream fin ("output.txt");
    char ch;
    while(fin.get(ch))
    {
        cout<<ch;
    }
    fin.close();
    return 0;
}
