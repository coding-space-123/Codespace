#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


class Solution 
{
public:
    vector<int> twoSum(vector<int>& arr, int target)
    {
        unordered_map<int,int> m;
        vector<int> ans;
        for(int i=0;i<arr.size();i++)
        {
            int f = arr[i];
            int sec = target - f;

            if(m.find(sec) != m.end()){
                ans.push_back(i);
                ans.push_back(m[sec]);
                break;
            }
             
            m[f]=i;
        }
        return ans;

    }
};