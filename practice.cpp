#include<bits/stdc++.h>
using namespace std;

int solve(string &str1, string &str2, int i, int j)
{
    if(i<0 || j<0)
    {
        return 0;
    }

    if(str1[i]==str2[j])
    {
        return 1 + solve(str1, str2, i-1, j-1);
    }

    return max(solve(str1, str2, i-1, j), solve(str1, str2, i, j-1));
}

int main()
{
    string str1,str2;
    cout<<"Enter string 1 : ";
    cin>>str1;
    cout<<"Enter string 2 : ";
    cin>>str2;

    vector<vector<int>>dp(str1.length()+1, vector<int>(str2.length()+1, -1));

    for(int i=0; i<str1.length()+1; i++) dp[i][0] = 0;
    for(int i=0; i<str2.length()+1; i++) dp[0][i] = 0;

    for(int i=1; i<=str1.length(); i++)
    {
        for(int j=1; j<=str2.length(); j++)
        {
            if(str1[i]==str2[j])
            {
                dp[i][j] =  1 + dp[i-1][j-1];
            }
            else
            {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    cout<<dp[str1.length()][str2.length()];
}