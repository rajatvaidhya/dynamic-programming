//Longest Palindromic Subsequence (Memoization & Tabulation)

#include<bits/stdc++.h>
using namespace std;

int solve(string &str1, string &str2, int i, int j, vector<vector<int>>&dp)
{
    if(i<0 || j<0)
    {
        return 0;
    }

    if(dp[i][j]!=-1) return dp[i][j];

    if(str1[i]==str2[j])
    {
        return dp[i][j] = 1+solve(str1, str2, i-1, j-1, dp);
    }

    return dp[i][j] = max(solve(str1, str2, i-1, j, dp), solve(str1, str2, i, j-1, dp));
}

int longestPalindromeSubseq(string s) {

    string str1 = s;
    vector<vector<int>>dp(s.length()+1, vector<int>(str1.length()+1, -1));
    reverse(str1.begin(), str1.end());

    for(int i=0; i<=s.length(); i++) dp[i][0] = 0;
    for(int i=0; i<=str1.length(); i++) dp[0][i] = 0;

    for(int i=1; i<=s.length(); i++)
    {
        for(int j=1; j<=str1.length(); j++)
        {
            if(s[i-1]==str1[j-1])
            {
                dp[i][j] = 1+dp[i-1][j-1];
            }
            else
            {
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }

    return dp[s.length()][str1.length()];
}


int main()
{
    string s;
    cout<<"Enter string : ";
    cin>>s;
    cout<<longestPalindromeSubseq(s)<<endl;
}