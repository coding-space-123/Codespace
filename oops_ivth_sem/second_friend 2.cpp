#include <iostream>
#include <iomanip>
using namespace std;


class box; 
int compute(box b1, box b2);
class box
{
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
    friend box compute(box b1, box b2);
};

box compute(box b1, box b2)
{
    if(b1.volume() > b2.volume())
        return *this;
    else
        return b2();
}


int main()
{
    box b1, b2,b3;
    cout << "Box Volume Comparison Program" << endl;
    cout << setfill('-') << setw(40) << "-" << endl;
    cout << "This program compares the volumes of two boxes." << endl;
    cout << "Enter details for Box 1:" << endl;
    b1.getdata();
    cout << "Enter details for Box 2:" << endl;
    b2.getdata();

    cout << "Box 1 details: ";
    b1.showdata();
    cout << "Volume of Box 1: " << b1.volume() << endl;

    cout << "Box 2 details: ";
    b2.showdata();
    cout << "Volume of Box 2: " << b2.volume() << endl;


    b3 = compute(b1 , b2);
    cout << "Larger volume is: " << b3;

    return 0;
}