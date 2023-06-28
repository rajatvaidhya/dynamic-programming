//Longest Common Subsequence (Memoization)

#include<bits/stdc++.h>
using namespace std;

int solve(string &str1, string &str2, int i, int j, vector<vector<int>>&dp)
{
    if(i<0 || j<0)
    {
        return 0;
    }

    if(dp[i][j]!=-1) return dp[i][j];

    int same = 0;

    if(str1[i]==str2[j])
    {
        same = 1 + solve(str1, str2, i-1, j-1, dp);
        return dp[i][j] = same;    
    }

    return dp[i][j] = max(solve(str1, str2, i-1, j, dp), solve(str1, str2, i, j-1, dp));
}

int longestCommonSubsequence(string text1, string text2) {

    vector<vector<int>>dp(text1.length(), vector<int>(text2.length(), -1));
    return solve(text1, text2, text1.length()-1, text2.length()-1, dp);
}

int main()
{
    string s1,s2;
    cout<<"Enter string 1 : ";
    cin>>s1;
    cout<<"Enter string 2 : ";
    cin>>s2;
    cout<<longestCommonSubsequence(s1, s2); 
}