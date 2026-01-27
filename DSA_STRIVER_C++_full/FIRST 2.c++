#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int LargestElement(vector <int> &a ,int n)
{
    int largest=a[0];
    for(int i=0;i<n;i++)
    {
        if(a[i]>largest)
            largest=a[i];

    }
    return largest;
}


// int main()
// {

//     int a[10],n;
//     cout<<"enter no. of element :";
//     cin >> n;
//     cout<<"\nenter elements :";
//     for(int i=0;i<n;i++)
//         cin>>a[i];
//     cout<< "\nelements are :";
//     for(int i=0;i<n ;i++)
//         cout << a[i];
//     int largest= a[0];
//     for(int i=0;i<n;i++)
//     {
//         if(a[i]>largest)
//             largest=a[i];
//     }
//     cout<<"\nlargest="<<largest;
//     return 0;
// }