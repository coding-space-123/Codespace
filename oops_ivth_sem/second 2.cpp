#include <iostream>
#include <iomanip>
using namespace std;

class box {
    int l,b,h;

public:
    void getdata()
    {
        cout << "Enter length, breadth and height of the box: ";
        cin >> l >> b >> h;
    }
    void showdata()
    {
        cout << "Length: " << l << endl << "Breadth: " << b << endl << "Height: " << h << endl;
    }
    int volume()
    {
        return l * b * h;
    }
    int compute(box b2)
    {
        if(volume() > b2.volume())
            return volume() ;
        else
            return b2.volume();
    }
};
int main()
{
    box b1, b2;
    cout << "Box Volume Comparison Program" << endl;
    cout << setfill('-') << setw(40) << "-" << endl;
    cout << "This program compares the volumes of two boxes." << endl;
    cout << "Enter details for Box 1:" << endl;
    b1.getdata();
    cout << "Enter details for Box 2:" << endl;
    b2.getdata();

    cout << "Box 1 details: ";
    b1.showdata();
    cout << "Box 2 details: ";
    b2.showdata();

    int larger_volume = b1.compute(b2);
    cout << "Larger volume is: " << larger_volume << endl;

    return 0;
}