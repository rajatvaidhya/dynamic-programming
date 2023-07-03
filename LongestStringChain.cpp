//Longest String Chain

#include<bits/stdc++.h>
using namespace std;

bool checkPossible(string &s1, string &s2)
{
    if(s1.length()!=s2.length()+1) return false;
    int f = 0;
    int s = 0;
        
    while(f<s1.length())
    {
        if(s1[f]==s2[s])
        {
            f++;
            s++;
        }
        else
        {
            f++;
        }
    }

    if(f>=s1.length() && s>=s2.length()) return true;
    return false;
}

static bool comp(string &s1, string &s2)
{
    return s1.length()<s2.length();
}

int longestStrChain(vector<string>& words) {

    sort(words.begin(), words.end(), comp);

    vector<int>dp(words.size(),0);
    dp[0] = 1;

    for(int i=1; i<words.size(); i++)
    {
        int maxLen = 1;

        for(int j=i-1; j>=0; j--)
        {
            if(checkPossible(words[i], words[j]))
            {
                maxLen = max(maxLen, dp[j]+1);
            }
        }

        dp[i] = maxLen;
    }

    int ans = INT_MIN;

    for(int i=0; i<dp.size(); i++)
    {
        ans = max(ans, dp[i]);
    }

    return ans;
}

int main()
{
    int n;
    cout<<"Enter size : ";
    cin>>n;
    vector<string>str;

    cout<<"Enter strings : ";

    for(int i=0; i<n; i++)
    {
        string s;
        cin>>s;
        str.push_back(s);
    }

    cout<<longestStrChain(str)<<endl;
}