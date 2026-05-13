#include<iostream>
#include<fstream>
using namespace std;

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        cout << "Usage: program source_file";
        return 0;
    }

    ifstream fin(argv[1]);

    if(!fin)
    {
        cout << "Source file not found";
        return 0;
    }

    char ch;

    while(fin.get(ch))
    {
        cout << ch;
    }

    fin.close();


    cout << "file display \n";

    return 0;
}