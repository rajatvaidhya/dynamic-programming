//0/1 Knapsack (Memoization)

#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>&wt, vector<int>&val, int W, int index, vector<vector<int>>&dp)
{
    if(index==0) 
    {
        if(wt[0]<=W)
        {
            return val[index];
        }
        else
        {
            return 0;
        }
    }
    
    if(dp[index][W]!=-1) return dp[index][W];
    
    int notTake = solve(wt, val, W, index-1, dp);
    int take = -1e9;
    
    if(wt[index]<=W)
    {
        take = val[index] + solve(wt, val, W-wt[index], index-1, dp);
    }
    
    return dp[index][W] = max(take, notTake);
}

int knapSack(int W, vector<int>&wt, vector<int>&val, int n) 
{ 
    vector<vector<int>>dp(n, vector<int>(W+1, -1));
    return solve(wt, val, W, n-1, dp);
}

int main()
{
    int n,k,W;
    cout<<"Enter size : ";
    cin>>n;
    vector<int>wt;
    vector<int>val;

    for(int i=0; i<n; i++)
    {
        int a;
        cin>>a;
        wt.push_back(a);
    }

    for(int i=0; i<n; i++)
    {
        int a;
        cin>>a;
        val.push_back(a);
    }

    cout<<"Enter bag weight : ";
    cin>>W;

    cout<<knapSack(W, wt, val, n);
}