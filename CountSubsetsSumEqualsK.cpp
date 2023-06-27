//Count Subsets Sum Equals K (Memoization)

#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>&nums, int index, int sum, int ans)
{
    if(sum==0) return 1;

    if(index==0) return nums[index]==sum;

    int notTake = solve(nums, index-1, sum, ans);
    int take = 0;

    if(nums[index]<=sum)
    {
        take = solve(nums, index-1, sum-nums[index], ans);
    }

    return take+notTake;
}

int main()
{
    int n,k,maxSum=0;
    cout<<"Enter size : ";
    cin>>n;
    vector<int>nums;

    for(int i=0; i<n; i++)
    {
        int a;
        cin>>a;
        nums.push_back(a);
    }

    cout<<"Enter k : ";
    cin>>k;

    int ans = 0;
    cout<<solve(nums, nums.size()-1, k, ans);
}