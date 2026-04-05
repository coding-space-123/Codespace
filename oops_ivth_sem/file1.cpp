#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    ifstream fin;
    fin.open("data.txt");

    char ch;
    while(fin.get(ch))
    {
        cout<<ch;
    }

    fin.close();
    return 0;
}