//Wildcard Matchin' - (Memoization)

#include<bits/stdc++.h>
using namespace std;

bool solve(string &s, string &t, int i, int j, vector<vector<int>>&dp)
{
    if(i<0 && j<0) return true;
    if(i<0 && j>=0) return false;

    if(j<0 && i>=0)
    {
        for(int k=0; k<=i; k++)
        {
            if(s[k]!='*')
            {
                return false;
            }
        }

        return true;
    }

    if(dp[i][j]!=-1) return dp[i][j];

    if(s[i]==t[j] || s[i]=='?')
    {
        return dp[i][j] = solve(s,t,i-1,j-1, dp);
    }

    if(s[i]=='*')
    {
        bool first = solve(s,t,i-1,j, dp);
        bool second = solve(s,t,i,j-1, dp);
        return dp[i][j] = first | second;
    }

    return dp[i][j] = false;
}

bool isMatch(string s, string t) {

    vector<vector<int>>dp(t.length(), vector<int>(s.length(), -1));
    return solve(t,s,t.length()-1, s.length()-1, dp);
}

int main()
{
    string s1,s2;
    cout<<"Enter normal string : ";
    cin>>s1;
    cout<<"Enter pattern : ";
    cin>>s2;
    cout<<isMatch(s1,s2)<<endl;
}