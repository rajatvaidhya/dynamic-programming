//Best Time to Buy and Sell Stocks with Cooldown - (Memoization)


#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>&prices, int index, int buy, vector<vector<int>>&dp)
{

    if(index>=prices.size()) return 0;

    int profit = 0;

    if(dp[index][buy]!=-1) return dp[index][buy];

    if(buy)
    {
        int b1 = -1*prices[index] + solve(prices, index+1, 0, dp);
        int b2 = solve(prices, index+1, 1, dp);
        profit = max(b1,b2);
    }
    else
    {
        int s1 = prices[index] + solve(prices, index+2, 1, dp);
        int s2 = solve(prices, index+1, 0, dp);
        profit = max(s1,s2);
    }

    return dp[index][buy] = profit;
}

int maxProfit(vector<int>& prices) {

    vector<vector<int>>dp(prices.size(), vector<int>(2, -1));
    return solve(prices, 0, 1, dp);
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