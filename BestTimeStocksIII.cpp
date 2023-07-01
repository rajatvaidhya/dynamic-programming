//Best Time to Buy and Sell Stocks - III (Memoization)

#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>&prices, int index, int buy, int cap, vector<vector<vector<int>>>&dp)
{
    if(cap==0) return 0;
    if(index==prices.size()) return 0;

    if(dp[index][buy][cap]!=-1) return dp[index][buy][cap];

    int profit = 0;

    if(buy)
    {
        int bought = -1*prices[index] + solve(prices, index+1, 0, cap, dp);
        int notBought = solve(prices, index+1, 1, cap, dp);
        profit = max(bought, notBought);
        return dp[index][buy][cap] = profit;
    }

    int sold = prices[index] + solve(prices, index+1, 1, cap-1, dp);
    int notSold = solve(prices, index+1, 0, cap, dp);
    profit = max(sold, notSold);
    return dp[index][buy][cap] = profit;
}

int maxProfit(vector<int>& prices) {

    vector<vector<vector<int>>>dp(prices.size(), vector<vector<int>>(2, vector<int>(3, -1)));
    int cap = 2;
    return solve(prices, 0, 1, cap, dp);
}

int main()
{
    int n;
    cout<<"Enter size : ";
    cin>>n;
    vector<int>vect;

    cout<<"Enter elements"<<endl;

    for(int i=0; i<n; i++)
    {
        int a;
        cin>>a;
        vect.push_back(a);
    }

    cout<<maxProfit(vect)<<endl;
}