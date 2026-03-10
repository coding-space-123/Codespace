#include<iostream>
using namespace std;

class a
{
    int x,y;
    public :
    a(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
    a& add(int z)
    {
        x += z;
        y += z;
        return *this;
    }
    void display()
    {
        cout << "x = " << x << ", y = " << y << endl;
    }
};
int main()
{
    a obj(10, 20);
    obj.add(5);
    obj.display();
    return 0;
}