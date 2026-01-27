#include <iostream>
#include <iomanip>
using namespace std;

class box;                       // forward declaration
box compare(box b1, box b2);     // friend function declaration

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

    friend box compare(box b1, box b2);
};

box compare(box b1, box b2)
{
    if (b1.l * b1.b * b1.h > b2.l * b2.b * b2.h)
        return b1;
    else
        return b2;
}


// box compare(box b1, box b2)
// {
//     if (b1.volume() > b2.volume())
//         return b1;
//     else
//         return b2;
// }

int main()
{
    box b1, b2, b3;

    cout << "Enter details for Box 1:\n";
    b1.getdata();

    cout << "Enter details for Box 2:\n";
    b2.getdata();

    cout << "\nBox 1 details:" << endl;
    b1.showdata();
    cout << "Volume of Box 1: " << b1.volume() << endl;

    cout << "\nBox 2 details:" << endl;
    b2.showdata();
    cout << "Volume of Box 2: " << b2.volume() << endl;


    b3 = compare(b1, b2);

    cout << "\nLarger box is: ";
    if (b3.volume() == b1.volume())
        cout << "b1\n";
    else
        cout << "b2\n";

    cout << "\nDetails of larger box:\n";
    b3.showdata();
    cout << "Volume: " << b3.volume() << endl;

    return 0;
}
