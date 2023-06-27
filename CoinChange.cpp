//Coin Change (Memoization)

#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>&coins, int index, int amount, vector<vector<int>>&dp)
{
    if(index==0)
    {
        if(amount%coins[0]==0) return amount/coins[0];
        else return 1e9;
    }

    if(dp[index][amount]!=-1) return dp[index][amount];
    
    int notTake = solve(coins, index-1, amount, dp);
    int take = 1e9;

    if(coins[index]<=amount)
    {
        take = 1 + solve(coins, index, amount-coins[index], dp);
    }

    return dp[index][amount] = min(take,notTake);
}

int coinChange(vector<int>& coins, int amount) {

    vector<vector<int>>dp(coins.size(), vector<int>(amount+1, -1));

    int ans = solve(coins, coins.size()-1, amount, dp);  

    if(ans==1e9)
    {
        return -1;
    } 

    return ans;
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

    cout<<coinChange(nums, amount);
}