//Subset Sum equals K (Memoization)

#include<bits/stdc++.h>
using namespace std;

bool solve(vector<int>&arr, int index, int target,vector<vector<int>>&dp)
{
    if(target==0) return true;
    if(index==0) return arr[0]==target;
    if(dp[index][target]!=-1) return dp[index][target];

    bool notTake = solve(arr, index-1, target, dp);
    bool take = false;

    if(target>=arr[index])
    {
        take = solve(arr, index-1, target-arr[index], dp);
    }

    return dp[index][target] = take or notTake;
}

int main()
{
    int n, target;
    cout<<"Enter array size : ";
    cin>>n;
    vector<int>arr;
    
    cout<<"Enter array elements"<<endl;
    
    for(int i=0; i<n; i++)
    {
        int a;
        cin>>a;
        arr.push_back(a);
    }

    cout<<"Enter target sum : ";
    cin>>target;

    vector<vector<int>>dp(arr.size()+1, vector<int>(target+1, -1));
    cout<<solve(arr, arr.size()-1, target, dp);
}