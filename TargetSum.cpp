//Target Sum - (Memoization)

#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>&nums, int index, int target, int sum, vector<vector<int>>&dp)
{
    if(index==nums.size())
    {
        if(target==sum)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    if(sum>=0)
    {
        if(dp[index][sum]!=-1) return dp[index][sum];
    }

    int take = solve(nums, index+1, target, sum+nums[index], dp);
    int notTake = solve(nums, index+1, target, sum-nums[index], dp);

    if(sum>=0)
    {
        dp[index][sum] = take+notTake;
    }

    return take+notTake;
}

int findTargetSumWays(vector<int>& nums, int target) {

    int maxTar = 0;
    
    for(int i=0; i<nums.size(); i++)
    {
        maxTar = maxTar + nums[i];
    }

    vector<vector<int>>dp(nums.size()+1, vector<int>(maxTar+1, -1));
    return solve(nums, 0, target, 0, dp);
}

int main()
{
    int n,target;
    cout<<"Enter size : ";
    cin>>n;
    vector<int>arr;

    cout<<"Enter elements"<<endl;

    for(int i=0; i<n; i++)
    {
        int a;
        cin>>a;
        arr.push_back(a);
    }

    cout<<"Enter target : ";
    cin>>target;
    cout<<findTargetSumWays(arr, target)<<endl;
}