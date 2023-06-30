//Distinct Subsequences (Memoization)

#include<bits/stdc++.h>
using namespace std;

int solve(string s, string t, int i, int j, vector<vector<int>>&dp)
{
    if(j<0) return 1;
    if(i<0) return 0;

    if(dp[i][j]!=-1) return dp[i][j];

    if(s[i]==t[j])
    {
        return dp[i][j] = solve(s,t,i-1,j-1,dp)+solve(s,t,i-1, j,dp);
    }

    return dp[i][j] = solve(s,t,i-1, j,dp);
}

int numDistinct(string s, string t) {

    vector<vector<int>>dp(s.length(), vector<int>(t.length(), -1));
    return solve(s, t, s.length()-1, t.length()-1,dp);
}

int main()
{
    string s,t;
    cout<<"Enter string 1 : ";
    cin>>s;
    cout<<"Enter string 2 : ";
    cin>>t;

    cout<<numDistinct(s,t)<<endl;
}