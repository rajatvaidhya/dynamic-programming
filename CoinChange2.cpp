//Coin Change-II (Memoization)

#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>&coins, int index, int amount, vector<vector<int>>&dp)
{
    if(index==0)
    {
        if(amount%coins[index]==0) return 1;
        return 0;
    }

    if(dp[index][amount]!=-1) return dp[index][amount];

    int notTake = solve(coins, index-1, amount, dp);
    int take = 0;

    if(coins[index]<=amount)
    {
        take = solve(coins, index, amount-coins[index], dp);
    }

    return dp[index][amount] = take+notTake;
}

int change(int amount, vector<int>& coins) {

    vector<vector<int>>dp(coins.size(), vector<int>(amount+1, -1));
    return solve(coins, coins.size()-1, amount, dp);
}

int main()
{
    int n, amount;
    cout<<"Enter size : ";
    cin>>n;
    vector<int>nums;

    for(int i=0; i<n; i++)
    {
        int a;
        cin>>a;
        nums.push_back(a);
    }

    cout<<"Enter amount : ";
    cin>>amount;

    cout<<change(amount, nums);
}