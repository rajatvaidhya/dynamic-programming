//Frog Jump with K jumps. (with Memoization)

#include<bits/stdc++.h>
using namespace std;

int frogJump(vector<int>&arr, int index, int k, int ans, vector<int>&dp)
{ 
    if(dp[index]!=-1)
    {
        return dp[index];
    }

    if(index==arr.size()-1)
    {
        return 0;
    }

    for(int i=1; i<=k; i++)
    {
        if((index+i)<arr.size())
        {
            int jump = frogJump(arr, index+i, k, ans, dp)+abs(arr[index]-arr[index+i]);
            ans = min(ans, jump);
        }
    }

    return dp[index] = ans;
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

    int k;
    cout<<"Enter k : ";
    cin>>k;

    cout<<frogJump(arr, 0, k, INT_MAX, dp)<<endl;


    //Tabulation Solution

    dp[0] = 0;

    for(int i=1; i<arr.size(); i++)
    {
        int minSteps = INT_MAX;

        for(int j=1; j<=k; j++)
        {
            if(i-j >= 0)
            {
                minSteps = min(minSteps, dp[i-j] + abs(arr[i]-arr[i-j]));
            }
        }

        dp[i] = minSteps;
    }

    cout<<dp[dp.size()-1]<<endl;
}