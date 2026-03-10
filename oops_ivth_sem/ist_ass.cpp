#include<iostream>
using namespace std;

class Number
{
    int a;
    float b;

public:

    Number()
    {
        a = 0;
        b = 0;
    }

    void input()
    {
        cout<<"Enter int value: ";
        cin>>a;

        cout<<"Enter float value: ";
        cin>>b;
    }

    void display()
    {
        cout<<"Int = "<<a<<endl;
        cout<<"Float = "<<b<<endl;
    }

    // Function overloading (int)
    int add(int x,int y)
    {
        return x + y;
    }

    // Function overloading (float)
    float add(float x,float y)
    {
        return x + y;
    }

    // + operator overloading
    Number operator+(Number n)
    {
        Number temp;

        temp.a = a + n.a;
        temp.b = b + n.b;

        return temp;
    }

    // ++ operator overloading
    Number operator++()
    {
        ++a;
        ++b;

        return *this;
    }

};

int main()
{
    Number n1,n2,n3;
    int ch;

    do
    {
        cout<<"\n1 Input Numbers";
        cout<<"\n2 Display Numbers";
        cout<<"\n3 Addition using + operator";
        cout<<"\n4 Increment (++ )";
        cout<<"\n5 Addition using Function Overloading";
        cout<<"\n6 Exit";

        cout<<"\nEnter choice: ";
        cin>>ch;

        switch(ch)
        {

        case 1:
            cout<<"\nEnter Number 1\n";
            n1.input();

            cout<<"\nEnter Number 2\n";
            n2.input();
            break;

        case 2:
            cout<<"\nNumber 1\n";
            n1.display();

            cout<<"\nNumber 2\n";
            n2.display();
            break;

        case 3:
            n3 = n1 + n2;
            cout<<"\nAfter Addition\n";
            n3.display();
            break;

        case 4:
            ++n1;
            cout<<"\nAfter Increment Number 1\n";
            n1.display();
            break;

        case 5:
        {
            int x,y;
            float p,q;

            cout<<"Enter two integers: ";
            cin>>x>>y;

            cout<<"Sum = "<<n1.add(x,y)<<endl;

            cout<<"Enter two floats: ";
            cin>>p>>q;

            cout<<"Sum = "<<n1.add(p,q)<<endl;

            break;
        }

        }

    }while(ch!=6);

    return 0;
}