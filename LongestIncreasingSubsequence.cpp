//Longest Increasing Subsequence

#include<bits/stdc++.h>
using namespace std;

int lengthOfLIS(vector<int>& arr) {
    
    int dp[arr.size()];
    
    for(int i=0; i<arr.size(); i++)
    {
        int maxlen = 0;
        
        for(int j=0; j<i; j++)
        {
            if(arr[j]<arr[i])
            {
                maxlen = max(maxlen, dp[j]);
            }
        }
        
        dp[i] = maxlen+1;
    }
    
    int ans = 0;
    
    for(int i=0; i<arr.size(); i++)
    {
        ans = max(ans, dp[i]);
    }
    
    return ans;
    
}

int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);

    for(int i=0; i<n; i++)
    {
        int a;
        cin>>a;
        arr.push_back(a);
    }

    cout<<lengthOfLIS(arr)<<endl;
}