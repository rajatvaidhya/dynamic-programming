//Longest Palindromic Subsequence

#include<bits/stdc++.h>
using namespace std;

int pal(string s, int l, int r)
{
    if(l>r || s==" ")
    {
        return 0;
    }
    
    while(l>=0 && r<s.length() && s[l]==s[r])
    {
        l--;
        r++;
    }
    
    return r-l-1;
}

string longestPalindrome(string s) {
    
    int start = -1;
    int maxLen = 0;
    
    for(int i=0; i<s.length(); i++)
    {
        int odd = pal(s,i,i);
        int even = pal(s,i,i+1);
        int len = max(even, odd);
        
        if(maxLen < len)
        {
            maxLen = len;
            start = i - (len-1)/2;
        }
    }
    
    return s.substr(start,maxLen);
}

int main()
{
    string str;
    cin>>str;
    cout<<longestPalindrome(str)<<endl;
}