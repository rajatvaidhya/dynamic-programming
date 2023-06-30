//Edit Distance - (Memoization)

#include<bits/stdc++.h>
using namespace std;

int solve(string s, string t, int i, int j, vector<vector<int>>&dp)
{
    if(i==0) return j;
    if(j==0) return i;
    if(dp[i][j]!=-1) return dp[i][j];
    if(s[i-1]==t[j-1]) return dp[i][j] = solve(s, t, i-1, j-1,dp);
    int insert = 1+solve(s, t, i, j-1,dp);
    int del = 1+solve(s, t, i-1, j,dp);
    int replace = 1+solve(s, t, i-1, j-1,dp);
    return dp[i][j] = min({insert, del, replace});
}

int minDistance(string word1, string word2) {

    vector<vector<int>>dp(word1.length(), vector<int>(word2.length(), -1));
    return solve(word1, word2, word1.length()-1, word2.length()-1, dp);
}

int main()
{
    string str1, str2;
    cout<<"Enter string 1 : ";
    cin>>str1;
    cout<<"Enter string 2 : ";
    cin>>str2;

    cout<<minDistance(str1,str2)<<endl;
}