#include<iostream>
using namespace std;

class Distance
{
    int metre;

public:

    // Parameterized constructor
    Distance(int m = 0)
    {
        metre = m;
    }

    // Friend functions
    friend istream& operator>>(istream&, Distance&);
    friend ostream& operator<<(ostream&, Distance&);
    friend void greaterDistance(Distance, Distance);
};

// Input operator >>
istream& operator>>(istream &in, Distance &d)
{
    cout<<"Enter distance in metre: ";
    in>>d.metre;
    return in;
}

// Output operator <<
ostream& operator<<(ostream &out, Distance &d)
{
    out<<"Distance = "<<d.metre<<" metre";
    return out;
}

// Friend function to compare
void greaterDistance(Distance d1, Distance d2)
{
    if(d1.metre > d2.metre)
        cout<<"\nFirst distance is greater";
    else if(d2.metre > d1.metre)
        cout<<"\nSecond distance is greater";
    else
        cout<<"\nBoth distances are equal";
}

int main()
{
    Distance d1, d2;

    cin>>d1;
    cin>>d2;

    cout<<"\nFirst Distance: "<<d1<<endl;
    cout<<"Second Distance: "<<d2<<endl;

    greaterDistance(d1,d2);

    return 0;
}