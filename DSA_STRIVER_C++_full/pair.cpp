//standard template library

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void explain_pair()
{
    // Simple pair
    pair<int,int> p1(1,4);
    cout << p1.first << " " << p1.second << endl;

    // Nested pair using constructor
    pair<int, pair<int,int>> p2(1, make_pair(3,5));
    cout << p2.first << " " << p2.second.first << " " << p2.second.second << endl;

    // Array of pairs
    pair<int,int> a[] = { {1,2}, {4,5}, {7,8} };
    cout << a[1].second << endl;  // prints 5
}

int main()
{
    explain_pair();
    return 0;
}




