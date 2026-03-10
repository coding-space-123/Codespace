#include<iostream>
using namespace std;

class Stack
{
    int st[3];
    int top;

public:

    // Default constructor
    Stack()
    {
        top = -1;
    }

    void push(int val)
    {
        if(top == 2)
        {
            cout<<"Stack Overflow\n";
        }
        else
        {
            top++;
            st[top] = val;
        }
    }

    void pop()
    {
        if(top == -1)
        {
            cout<<"Stack Underflow\n";
        }
        else
        {
            cout<<"Deleted element: "<<st[top]<<endl;
            top--;
        }
    }

    void display()
    {
        if(top == -1)
        {
            cout<<"Stack is Empty\n";
        }
        else
        {
            cout<<"Stack elements:\n";
            for(int i=top;i>=0;i--)
                cout<<st[i]<<" ";
            cout<<endl;
        }
    }

    void isempty()
    {
        if(top==-1)
            cout<<"Stack is Empty\n";
        else
            cout<<"Stack is not Empty\n";
    }

    void isfull()
    {
        if(top==99)
            cout<<"Stack is Full\n";
        else
            cout<<"Stack is not Full\n";
    }
};

int main()
{
    Stack s;
    int ch,val;

    do
    {
        cout<<"\n1 Push";
        cout<<"\n2 Pop";
        cout<<"\n3 Display";
        cout<<"\n4 Check Empty";
        cout<<"\n5 Check Full";
        cout<<"\n6 Exit";

        cout<<"\nEnter choice: ";
        cin>>ch;

        switch(ch)
        {

        case 1:
            cout<<"Enter value: ";
            cin>>val;
            s.push(val);
            break;

        case 2:
            s.pop();
            break;

        case 3:
            s.display();
            break;

        case 4:
            s.isempty();
            break;

        case 5:
            s.isfull();
            break;

        }

    }while(ch!=6);

    return 0;
}