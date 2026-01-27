#include<iostream>
#include<math.h>
#include<string>
// #include<bits/stdc++.h>     // includes all standard libraries
using namespace std;



int sum(int a , int b)
{
    return a + b;
}


int main()
{
    // int   restriction  4 bytes range -2147483648 to 2147483647
    int a=10;
    //long                4 bytes range -2,147,483,648 to 2,147,483,647
    long b=123456;
    cout<<"b = "<<b<<endl;
    //long long               8 bytes range -9,223,372,036,854,775,808 to 9,223,372,036,854,775,807
    long long c1=1234567890;
    cout<<"c1 = "<<c1<<endl;


    //float               4 bytes range 1.2E-38 to 3.4E+38 precision 6-7 decimal digits
    float d=5.67;
    cout<<"d = "<<d<<endl;
    //double              8 bytes range 2.3E-308 to 1.7E+308 precision 15 decimal digits
    double e=9.123456;
    cout<<"e = "<<e<<endl;
    //long double         10 bytes range 3.4E-4932 to 1.1E+4932 precision 18 decimal digits
    long double f=1.23456789;
    cout<<"f = "<<f<<endl;


    
    //short               2 bytes range -32,768 to 32,767
    //unsigned long       4 bytes range 0 to 4,294,967,295
    //unsigned short         4 bytes range 0 to 65,535


    //string and getline 
    // string s1,s2;
    // cin>>s1>>s2;
    // cout <<s1 <<" "<<s2;

    // string str ;
    // getline(cin , str);
    // cout << str;

    // char                1 byte range -128 to 127
    // char c='A';
    // cout <<"\nc="<< c <<endl;
    // string ch = " siyaram ";


    // WAP that takes an input of age 
    // and prints if u are adults or not 
    // int age;
    // cout<<"enter age of person=";
    // cin >> age;
    // if(age >= 18)
        // cout<<"adult";
    // else if(age < 18)
        // cout<<"person not adults\n";
    // else 
        // return 0;
    // 

    //nested if-else
    // int num;
    // cout<<"enter number=";
    // cin >> num;
    // if(num > 0)
    // {
        // cout<<"number is positive\n";
        // if(num % 2 == 0)
            // cout<<"number is even\n";
        // else
            // cout<<"number is odd\n";
    // }
    // else if(num < 0)
        // cout<<"number is negative\n";
    // else
        // cout<<"number is zero\n";

    // switch case
    // int day;
    // cout<<"enter day number=";
    // cin >> day;
    // switch(day)
    // {
        // case 1:
            // cout<<"monday\n";
            // break;
        // case 2:
            // cout<<"tuesday\n";
            // break;
        // case 3:
            // cout<<"wednesday\n";
            // break;
        // case 4:
            // cout<<"thursday\n";
            // break;
        // case 5:
            // cout<<"friday\n";
            // break;
        // case 6:
            // cout<<"saturday\n";
            // break;
        // case 7:
            // cout<<"sunday\n";
            // break;
        // default:
            // cout<<"invalid day number\n";
    // }
    // return 0;

    // arrays , strings
    // int arr[5] = {1,2,3,4,5};
    // cin >> arr[0] >> arr[1] >> arr[2] >> arr[3] >> arr[4];
    // cout << arr[0] <<" " << arr[1] <<" " << arr[2] <<" " << arr[3] <<" " << arr[4] << endl;


    //2d arrays
    int arr[3][5];
    arr[1][3] = 70;
    cout << arr[1][3] << endl;

    // string
    cout<<"string example:"<<endl;
    string str = "hello";
    int len = str.size();
    str[len - 1] = 'a';
    cout << str[len - 1] << endl;



    // for loop
    cout<<"for loop output:"<<endl;
    for(int i=0; i<5; i++)
    {
        cout << i << " ";
    }
    cout << endl;

    cout<<"while loop and do while loop output:"<<endl;
    // while loop
    int i=0;
    while(i<5)
    {
        cout << i << " ";
        i++;
    }
    cout << endl;
    // do while loop
    int j=2;
    do
    {
        cout << j << " ";
        j++;
    } while(j>5);
    cout << endl;

    // functions are set of code which performs sth for u
    //functions are used to mudularised code 
    //functions are used to increase readability
    //fuction are used to use same code multiple times
    // void - which does not return any value 
    // return - returns value 
    // parameterised 
    // non - parameterised 

    // pass by value 
    // pass by reference 


    cout<<"sum="<< sum(4,8);




    return 0;




} 
