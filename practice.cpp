#include<bits/stdc++.h>
using namespace std;

bool solve(vector<int>&nums, int index, int target, vector<vector<int>>&dp)
{
    if(target==0) return true;
    if(index==0) return nums[0]==target;
    if(dp[index][target]!=-1) return dp[index][target];

    bool notTake = solve(nums, index-1, target, dp);
    bool take = false;

    if(target>=nums[index])
    {
        take = solve(nums, index-1, target-nums[index], dp);
    }

    return dp[index][target] = take || notTake;
}

int minimumDifference(vector<int>& nums) {

    int sum = 0;
    for(int i=0; i<nums.size(); i++) sum += nums[i];
    vector<vector<int>>dp(nums.size(), vector<int>(sum+1, -1));
    solve(nums, nums.size()-1, sum, dp);

    for(int i=0; i<nums.size(); i++)
    {
        for(int j=0; j<sum+1; j++)
        {
            cout<<dp[i][j]<<" ";
        }

        cout<<endl;
    }

    return -1;
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

    cout<<minimumDifference(nums)<<endl;
}