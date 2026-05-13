#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream fin("data.txt");   // open in read mode
    string line;

    if (!fin) {
        cout << "File not found!";
        return 1;
    }

    // while (getline(fin, line)) {
    //     cout << line << endl;
    // }
    char ch;
    while (fin.get(ch))
    {
        cout<<ch ;
    }
    cout<<endl;
    fin.close();
    return 0;
}