/*Multispaces converted into single space in destination file*/

#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    ifstream fin("student.txt");
    ofstream fout("dest.txt");

    if(!fin)
    {
        cout<<"Source file not found";
        return 0;
    }

    char ch;
    bool spaceFlag = false;   // track space

    while(fin.get(ch))
    {
        if(ch == ' ')
        {
            // अगर पहले space नहीं आया
            if(!spaceFlag)
            {
                fout.put(ch);
                spaceFlag = true;
            }
        }
        else
        {
            fout.put(ch);
            spaceFlag = false;
        }
    }

    fin.close();
    fout.close();

    cout<<"File processed successfully";
    return 0;
}