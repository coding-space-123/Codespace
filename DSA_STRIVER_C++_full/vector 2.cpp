//standard template library

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void explain_vector()
{
    vector<int> v;    // empty vector create
    v.push_back (1);
    v.emplace_back(2); //faster then push back

    vector<pair <int, int>>vec;
    v.push_back({1,2});
    v.emplace_back(1,2);  // automatically assume (1,2) is pair

    vector <int> v(5,100);

    vector<int> v(5);
    vector <int>v1(5,20);
    vector <int> v2(v1);

    vector<int> :: iterator it= v.begin;
}

int main()
{
    explain_vector();
    return 0;
}
