//Largest Divisible Subsets

#include<bits/stdc++.h>
using namespace std;

vector<int> largestDivisibleSubset(vector<int>& nums) {

    sort(nums.begin(), nums.end());

    vector<int>dp(nums.size());
    vector<int>index(nums.size());
    index[0] = 0;
    dp[0] = 1;

    for(int i=1; i<nums.size(); i++)
    {
        int in = i;
        int maxLen = 1;

        for(int j=i-1; j>=0; j--)
        {
            if(nums[i]%nums[j]==0)
            {
                if(maxLen < dp[j]+1)
                {
                    in = j;
                    maxLen = dp[j]+1;
                } 
            }
        }

        dp[i] = maxLen;
        index[i] = in;
    }

    vector<int>ans;
    int maxIn = 0;
    int maxi = INT_MIN;
    int maxNum = INT_MIN;

    for(int i=0; i<dp.size(); i++)
    {
        if(maxi < dp[i])
        {
            maxi = dp[i];
            maxIn = index[i];
            maxNum = nums[i];
        }
    }

    ans.push_back(maxNum);
    int count = maxi;
    count--;

    while(count > 0)
    {
        ans.push_back(nums[maxIn]);
        maxIn = index[maxIn];
        count--;
    }

    reverse(ans.begin(),ans.end());
    return ans;
}

int main()
{
    int n;
    cout<<"Enter size : ";
    cin>>n;

    vector<int>nums;

    cout<<"Enter elements : ";
    
    for(int i=0; i<n; i++)
    {
        int a;
        cin>>a;
        nums.push_back(a);
    }

    vector<int> ans = largestDivisibleSubset(nums);

    for(int i=0; i<ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
}