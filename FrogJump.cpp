//Frog Jump (with Memoization)

#include<bits/stdc++.h>
using namespace std;

int frogJump(vector<int>&arr, int index, vector<int>&dp)
{
    if(dp[index]!=-1)
    {
        return dp[index];
    }
    
    if(index==arr.size()-1)
    {
        return 0;
    }

    int right = INT_MAX;

    int left = frogJump(arr, index+1, dp) + abs(arr[index]-arr[index+1]);

    if(index<arr.size()-2)
    {
        right = frogJump(arr, index+2, dp) + abs(arr[index]-arr[index+2]);
    }

    return dp[index] = min(left,right);
}

int main()
{
    int n;
    cout<<"Enter size : ";
    cin>>n;
    vector<int>arr;
    vector<int>dp(n, -1);

    cout<<"Enter elements : ";
    
    for(int i=0; i<n; i++)
    {
        int a;
        cin>>a;
        arr.push_back(a);
    }

    cout<<frogJump(arr, 0, dp)<<endl;
}