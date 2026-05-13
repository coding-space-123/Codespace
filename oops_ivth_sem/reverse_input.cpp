#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    ofstream fout1("student.txt");   // write input

    if(!fout1)
    {
        cout<<"Error creating file!\n";
        return 1;
    }

    cout<<"Enter text (end with #):\n";

    char ch;

    // 🔹 Take input from user
    while(cin.get(ch))
    {
        if(ch == '#')   // termination condition
            break;
        fout1.put(ch);
    }

    fout1.close();

    // 🔹 Open file for reading
    ifstream fin("student.txt");
    ofstream fout2("reverse.txt");

    if(!fin)
    {
        cout<<"Error opening file!\n";
        return 1;
    }

    // Move pointer to end
    fin.seekg(0, ios::end);
    int pos = fin.tellg();

    // 🔹 Reverse logic
    for(int i = pos - 1; i >= 0; i--)
    {
        fin.seekg(i);
        fin.get(ch);
        fout2.put(ch);
        cout<<ch;
    }

    fin.close();
    fout2.close();

    cout<<"\nFile reversed successfully!\n";

    return 0;
} 

/*
output:
Enter text (end with #):
hloo , how are u
#

File reversed successfully!

student.txt file :hloo , how are u
reverse.txt file :u era woh , oolh
*/