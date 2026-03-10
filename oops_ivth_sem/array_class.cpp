#include<iostream>
using namespace std;

class Array
{
    int arr[100];

public:
    int size;

    Array()
    {
        size = 0;
    }

    // Subscript operator overloading
    int& operator[](int index)
    {
        return arr[index];
    }

    friend ostream& operator<<(ostream &out, Array &a);
};

ostream& operator<<(ostream &out, Array &a)
{
    for(int i=0;i<a.size;i++)
        out<<a[i]<<" ";

    out<<endl;
    return out;
}

int main()
{
    Array a;
    int ch,val,pos,n;

    do
    {
        cout<<"\n1 Input Array";
        cout<<"\n2 Insert Beginning";
        cout<<"\n3 Insert End";
        cout<<"\n4 Insert Position";
        cout<<"\n5 Delete Beginning";
        cout<<"\n6 Delete End";
        cout<<"\n7 Delete Position";
        cout<<"\n8 Display";
        cout<<"\n9 Exit";

        cout<<"\nEnter choice: ";
        cin>>ch;

        switch(ch)
        {

        case 1:
            cout<<"Enter number of elements: ";
            cin>>n;

            a.size = n;

            cout<<"Enter elements:\n";
            for(int i=0;i<n;i++)
                cin>>a[i];      // using overloaded []

            break;

        case 2:
            cout<<"Enter value: ";
            cin>>val;

            for(int i=a.size;i>0;i--)
                a[i] = a[i-1];

            a[0] = val;
            a.size++;
            break;

        case 3:
            cout<<"Enter value: ";
            cin>>val;

            a[a.size] = val;
            a.size++;
            break;

        case 4:
            cout<<"Enter value and position: ";
            cin>>val>>pos;

            for(int i=a.size;i>pos;i--)
                a[i] = a[i-1];

            a[pos] = val;
            a.size++;
            break;

        case 5:
            for(int i=0;i<a.size-1;i++)
                a[i] = a[i+1];

            a.size--;
            break;

        case 6:
            a.size--;
            break;

        case 7:
            cout<<"Enter position: ";
            cin>>pos;

            for(int i=pos;i<a.size-1;i++)
                a[i] = a[i+1];

            a.size--;
            break;

        case 8:
            cout<<a;
            break;

        }

    }while(ch!=9);

    return 0;
}