//Best Time to Buy and Sell Stocks - IV (Memoization)

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
        int b1 = -1*prices[index] + solve(prices, index+1, 0, cap, dp);
        int b2 = solve(prices, index+1, 1, cap, dp);
        profit = max(b1,b2);
    }
    else
    {
        int s1 = prices[index] + solve(prices, index+1, 1, cap-1, dp);
        int s2 = solve(prices, index+1, 0, cap, dp);
        profit = max(s1,s2);
    }

    return dp[index][buy][cap] = profit;
}

int maxProfit(int k, vector<int>& prices) {

    vector<vector<vector<int>>>dp(prices.size(), vector<vector<int>>(2, vector<int>(k+1, -1)));
    return solve(prices, 0, 1, k, dp);
}

int main()
{
    int n,k;
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

    cout<<"Enter K : ";
    cin>>k;
    cout<<maxProfit(k, vect)<<endl;
}