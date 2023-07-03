//Printing Longest Increasing Subsequence

#include<bits/stdc++.h>
using namespace std;

void printLIS(vector<int>&nums)
{
    vector<int>index(nums.size()), dp(nums.size());
    dp[0] = 1;
    index[0] = 0;

    for(int i=1; i<nums.size(); i++)
    {
        int maxLen = 1;
        int in = i;

        for(int j=i-1; j>=0; j--)
        {
            if(nums[i]>nums[j])
            {
                if(maxLen<dp[j]+1)
                {
                    maxLen = dp[j]+1;
                    in = j;
                }
            }
        }

        dp[i] = maxLen;
        index[i] = in;
    }

    int maxIn = 0;
    int maxNum = INT_MIN;
    int num = 0;

    for(int i=0; i<dp.size(); i++)
    {
        if(maxNum < dp[i])
        {
            maxNum = dp[i];
            maxIn = index[i];
            num = nums[i];
        }
    }

    cout<<num<<" ";

    maxNum--;

    while(maxNum>0)
    {
        cout<<nums[maxIn]<<" ";
        maxIn = index[maxIn]; 
        maxNum--;
    }
}

int main()
{
    int n;
    cout<<"Enter size : ";
    cin>>n;
    vector<int>nums;

    for(int i=0; i<n; i++)
    {
        int a;
        cin>>a;
        nums.push_back(a);
    }

    printLIS(nums);
}