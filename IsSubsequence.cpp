//Is Subsequence Problem (Easy)

#include<bits/stdc++.h>
using namespace std;

bool isSubsequence(string s, string t) {

    if(t.length()==0 && s.length()==0) return true;
    if(t.length()<s.length()) return false;

    int l = 0;
    int h = 0;

    while(h<t.length())
    {
        if(s[l]==t[h])
        {
            l++; 
            h++;
        } 
        else 
        {
            h++;
        }

        if(l>=s.length()) return true;
    }

    return false;
}

int main()
{
    string s,t;
    cout<<"Enter string 1 : ";
    cin>>s;
    cout<<"Enter string 2 : ";
    cin>>t;
    cout<<isSubsequence(s,t)<<endl;
}