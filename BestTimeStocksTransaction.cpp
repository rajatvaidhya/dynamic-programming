//Best Time to Buy and Sell Stocks with Transaction Fees - (Memoization)

#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>&prices, int index, int buy, int fee, vector<vector<int>>&dp)
{
    if(index==prices.size()) return 0;

    int profit = 0;

    if(dp[index][buy]!=-1) return dp[index][buy];
    
    if(buy)
    {
        int b1 = -1*prices[index] + solve(prices, index+1, 0, fee, dp);
        int b2 = solve(prices, index+1, 1, fee, dp);
        profit = max(b1,b2);
    }
    else
    {
        int s1 = prices[index] - fee + solve(prices, index+1, 1, fee, dp);
        int s2 = solve(prices, index+1, 0, fee, dp);
        profit = max(s1, s2); 
    }

    return dp[index][buy] = profit;
}

int maxProfit(vector<int>& prices, int fee) {

    vector<vector<int>>dp(prices.size(), vector<int>(2, -1));
    return solve(prices, 0, 1, fee, dp);
}

int main()
{
    int n,fee;
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

    cout<<"Enter transaction fees : ";
    cin>>fee;

    cout<<maxProfit(vect, fee)<<endl;
}