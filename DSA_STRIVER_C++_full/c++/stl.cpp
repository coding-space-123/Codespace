#include<iostream>
#include<vector>
#include<list>
#include<deque>
using namespace std;
int main()
{
    vector<int>v;
    v.push_back(23);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(9);
    v.push_back(21);
    v.pop_back();
    
    for(int val: v)
    {
        cout <<" " << val;
    }
    

}