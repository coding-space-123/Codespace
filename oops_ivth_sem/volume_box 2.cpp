#include <iostream>
#include <iomanip>
using namespace std;
box compare(box b2);
class box
{
    int l, b, h;

public:
    void getdata()
    {
        cout << "Enter length, breadth and height of the box: ";
        cin >> l >> b >> h;
    }

    void showdata()
    {
        cout << "Length: " << l << endl;
        cout << "Breadth: " << b << endl;
        cout << "Height: " << h << endl;
    }

    int volume()
    {
        return l * b * h;
    }

    // member function compare
    friend box compare( box b2);
};

box compare(box b2)
    {
        if (this->volume() > b2.volume())
            return *this;
        else
            return b2;
    }

int main()
{
    box b1, b2, b3;

    cout << "Box Volume Comparison Program" << endl;
    cout << setfill('-') << setw(40) << "-" << endl;

    cout << "Enter details for Box 1:" << endl;
    b1.getdata();

    cout << "Enter details for Box 2:" << endl;
    b2.getdata();

    cout << "\nBox 1 details:" << endl;
    b1.showdata();
    cout << "Volume of Box 1: " << b1.volume() << endl;

    cout << "\nBox 2 details:" << endl;
    b2.showdata();
    cout << "Volume of Box 2: " << b2.volume() << endl;

    // compare using member function
    b3 = b1.compare(b2);

    cout << "\nLarger box is: " ;
    if (b3.volume() == b1.volume())
        cout << "b1" << endl;
    else
        cout << "b2" << endl;

    cout << "\nDetails of larger box:" << endl;
    b3.showdata();
    cout << "Volume: " << b3.volume() << endl;

    return 0;
}