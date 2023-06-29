//Delete Operations for Two Strings

#include<bits/stdc++.h>
using namespace std;

int solve(string &str1, string &str2, int i, int j, vector<vector<int>>&dp)
{
    if(i<0 || j<0) return 0;
    if(dp[i][j]!=-1) return dp[i][j];

    if(str1[i]==str2[j]) return dp[i][j] = 1+solve(str1, str2, i-1, j-1, dp);
    return dp[i][j] = max(solve(str1, str2, i-1, j, dp), solve(str1, str2, i, j-1, dp));
}

int minDistance(string word1, string word2) {

    vector<vector<int>>dp(word1.length()+1, vector<int>(word2.length()+1, -1));
    int lcs = solve(word1, word2, word1.length()-1, word2.length()-1, dp);
    int ans1 = word1.length()-lcs;
    int ans2 = word2.length()-lcs;
    return ans1+ans2;
}

int main()
{
    string s1,s2;
    cout<<"Enter string 1 : ";
    cin>>s1;
    cout<<"Enter string 2 : ";
    cin>>s2;
    cout<<minDistance(s1, s2)<<endl;
}