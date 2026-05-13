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
    cout<<"\ncreate Array:\n";
    cout<<"Enter number of elements: ";
        cin>>n;

        a.size = n;

        cout<<"Enter elements:\n";
        for(int i=0;i<n;i++)
            cin>>a[i]; 
    do
    {
        
        cout<<"\n1 Insert Beginning";
        cout<<"\n2 Insert End";
        cout<<"\n3 Insert Position";
        cout<<"\n4 Delete Beginning";
        cout<<"\n5 Delete End";
        cout<<"\n6 Delete Position";
        cout<<"\n7 Display";
        cout<<"\n8 Exit";

        cout<<"\nEnter choice: ";
        cin>>ch;

        switch(ch)
        {
        case 1:
            cout<<"Enter value: ";
            cin>>val;

            for(int i=a.size;i>0;i--)
                a[i] = a[i-1];

            a[0] = val;
            a.size++;
            break;

        case 2:
            cout<<"Enter value: ";
            cin>>val;

            a[a.size] = val;
            a.size++;
            cout<<"insert value succesfully !\n";
            break;
        case 3:
            cout<<"Enter value and position: ";
            cin>>val>>pos;
            if(pos < 0 || pos > a.size)
            {
                cout<<"Invalid position!\n";
                break;
            }
            for(int i=a.size;i>pos;i--)
                a[i] = a[i-1];

            a[pos] = val;
            a.size++;
            cout<<"insert value succesfully !\n";
            break;

        case 4:
            if(a.size == 0)
            {
                cout<<"Array is empty!\n";
                break;
            }
            cout<<"value is deleted : "<<a[0]<<endl;
            for(int i=0;i<a.size-1;i++)
                a[i] = a[i+1];

            a.size--;

            break;

        case 5:
            if(a.size == 0)
            {
                cout<<"Array is empty!\n";
                break;
            }
            cout<<"delete value succesfully !\n value = "<<a.size;
            a.size--;
            break;

        case 6:
            if(a.size == 0)
            {
                cout<<"Array is empty!\n";
                break;
            }
            cout<<"Enter position: ";
            cin>>pos;
            if(pos >= 0 && pos < a.size)
            {
                for(int i=pos;i<a.size-1;i++)
                    a[i] = a[i+1];

                a.size--;
            }
            else
                cout<<"Invalid position!\n";
            break;

        case 7:
            if(a.size == 0)
            {
                cout<<"Array is empty!\n";
                break;
            }
            cout<<"element in array is : ";
            cout<<a;
            break;
        case 8: 
            exit(0);
        default :
            cout<<"invalid choice !\n";
        }

    }while(ch!=8);

    return 0;
}