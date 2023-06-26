//Partition Equal Subset Sum (Memoization)

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

    return dp[index][target] = take or notTake;
}

bool canPartition(vector<int>& nums) {

    int sum = 0;
    for(int i=0; i<nums.size(); i++) sum+=nums[i];

    if(sum%2!=0) return false;

    vector<vector<int>>dp(nums.size()+1, vector<int>(sum/2+1, -1));
    return solve(nums, nums.size()-1, sum/2, dp);
}

int main()
{
    int n, target;
    cout<<"Enter array size : ";
    cin>>n;
    vector<int>arr;
    
    cout<<"Enter array elements"<<endl;
    
    for(int i=0; i<n; i++)
    {
        int a;
        cin>>a;
        arr.push_back(a);
    }

    cout<<canPartition(arr)<<endl;
}