#include<iostream>
#include<fstream>
using namespace std;

int main(int argc, char *argv[])
{
    if(argc != 3)
    {
        cout << "Usage: program source_file destination_file";
        return 0;
    }

    ifstream fin(argv[1]);
    ofstream fout(argv[2]);

    if(!fin)
    {
        cout << "Source file not found";
        return 0;
    }

    char ch;

    while(fin.get(ch))
    {
        fout.put(ch);
    }

    fin.close();
    fout.close();

    cout << "File copied successfully";

    return 0;
}