//Shortest Common Subsequences

#include<bits/stdc++.h>
using namespace std;

string shortestCommonSupersequence(string text1, string text2) {

    vector<vector<int>>dp(text1.size()+1, vector<int>(text2.size()+1, 0));

    for(int i=0; i<text1.size()+1; i++) dp[i][0] = 0; 
    for(int i=0; i<text2.size()+1; i++) dp[0][i] = 0;

    for(int i=1; i<=text1.size(); i++)
    {
        for(int j=1; j<=text2.size(); j++)
        {
            if(text1[i-1]==text2[j-1])
            {
                dp[i][j] = 1+dp[i-1][j-1];
            }
            else
            {
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    } 

    string ans = "";

    int i=text1.length();
    int j=text2.length();

    while(i>0 && j>0)
    {
        if(text1[i-1]==text2[j-1])
        {
            ans = ans + text1[i-1];
            i--; j--;
        }
        else if(dp[i-1][j] > dp[i][j-1])
        {
            ans = ans + text1[i-1];
            i--;
        }
        else
        {
            ans = ans + text2[j-1];
            j--;
        }
    }
    
    while(i>0)
    {
        ans = ans + text1[i-1];
        i--;
    }

    while(j>0)
    {
        ans = ans + text2[j-1];
        j--;
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    string s1,s2;
    cout<<"Enter string 1 : ";
    cin>>s1;
    cout<<"Enter string 2 : ";
    cin>>s2;
    cout<<shortestCommonSupersequence(s1,s2)<<endl;
}