//Minimum Insertions to make strings palindrome

#include<bits/stdc++.h>
using namespace std;

int solve(string &str1, string &str2, int i, int j, vector<vector<int>>&dp)
{
    if(i<0 || j<0) return 0;
    if(dp[i][j]!=-1) return dp[i][j];

    if(str1[i]==str2[j])
    {
        return dp[i][j] = 1+solve(str1, str2, i-1, j-1, dp);
    }

    return dp[i][j] = max(solve(str1, str2, i-1, j, dp), solve(str1, str2, i, j-1, dp));
}

int minInsertions(string s) {

    string str = s;
    vector<vector<int>>dp(s.length()+1, vector<int>(str.length()+1, -1));
    reverse(str.begin(), str.end());
    int lcs = solve(s, str, s.length()-1, str.length()-1, dp);
    return s.length()-lcs;
}

int main()
{
    string str;
    cout<<"Enter string : ";
    cin>>str;
    cout<<minInsertions(str)<<endl;
}