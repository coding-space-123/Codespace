#include<iostream>
using namespace std;

class Demo {
    int arr[5];
    int val;

public:
    // Constructor
    Demo() {
        val = 0;
        for(int i=0;i<5;i++)
            arr[i] = 0;
    }

    // 🔹 Assignment operator (=)
    Demo operator=(Demo d) {
        val = d.val;
        for(int i=0;i<5;i++)
            arr[i] = d.arr[i];
        return *this;
    }

    // 🔹 Subscript operator []
    int& operator[](int index) {
        if(index<0 || index>=5) {
            cout<<"Index out of bound!\n";
            exit(0);
        }
        return arr[index];
    }

    // 🔹 Function call operator ()
    void operator()(int x) {
        val = x;
        cout<<"Value set using (): "<<val<<endl;
    }

    // 🔹 Arrow operator ->
    Demo* operator->() {
        return this;
    }

    // 🔹 Greater than >
    bool operator>(Demo d) {
        return val > d.val;
    }

    // 🔹 Less than <
    bool operator<(Demo d) {
        return val < d.val;
    }

    // 🔹 Equal to ==
    bool operator==(Demo d) {
        return val == d.val;
    }

    // 🔹 Input >>
    friend istream& operator>>(istream& in, Demo& d);

    // 🔹 Output <<
    friend ostream& operator<<(ostream& out, Demo& d);

    void show() {
        cout<<"Value = "<<val<<endl;
    }
};

// Input
istream& operator>>(istream& in, Demo& d) {
    cout<<"Enter value: ";
    in>>d.val;

    cout<<"Enter "<<d.val<<" array elements: ";
    for(int i=0;i<d.val;i++)
        in>>d.arr[i];

    return in;
}

// Output
ostream& operator<<(ostream& out, Demo& d) {
    out<<"Value = "<<d.val<<endl;
    out<<"Array: ";
    for(int i=0;i<d.val;i++)
        out<<d.arr[i]<<" ";
    return out;
}

// 🔹 Main (Menu Driven)
int main() {
    Demo d1, d2;
    int ch;

    do {
        cout<<"\n===== MENU =====";
        cout<<"\n1 Input";
        cout<<"\n2 Display";
        cout<<"\n3 Assignment (=)";
        cout<<"\n4 Subscript []";
        cout<<"\n5 Function Call ()";
        cout<<"\n6 Arrow ->";
        cout<<"\n7 Comparison (>, <, ==)";
        cout<<"\n8 Exit";

        cout<<"\nEnter choice: ";
        cin>>ch;

        switch(ch) {

            case 1:
                cout<<"Enter d1:\n";
                cin>>d1;
                cout<<"Enter d2:\n";
                cin>>d2;
                break;

            case 2:
                cout<<"\nd1:\n"<<d1<<endl;
                cout<<"\nd2:\n"<<d2<<endl;
                break;

            case 3:
                d2 = d1;
                cout<<"After assignment d2 = d1:\n"<<d2<<endl;
                break;

            case 4:
            {
                int i;
                cout<<"Enter index (0-4): ";
                cin>>i;

                cout<<"Current value: "<<d1[i]<<endl;

                cout<<"Enter new value: ";
                cin>>d1[i];

                cout<<"Updated array:\n"<<d1<<endl;
                break;
            }

            case 5:
            {
                int x;
                cout<<"Enter value: ";
                cin>>x;
                d1(x);
                break;
            }

            case 6:
                d1->show();
                break;

            case 7:
                if(d1 > d2)
                    cout<<"d1 > d2\n";
                else if(d1 < d2)
                    cout<<"d1 < d2\n";
                else if(d1 == d2)
                    cout<<"d1 == d2\n";
                break;

            case 8:
                cout<<"Exiting...\n";
                break;

            default:
                cout<<"Invalid choice!\n";
        }

    } while(ch != 8);

    return 0;
}