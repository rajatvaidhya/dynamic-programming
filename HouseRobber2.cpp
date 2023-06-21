//House Robber II (Tabulation - Memory Optimised)

#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>&nums, int firstIndex, int leftIndex)
{
    int prevMax = nums[firstIndex];
    int currentMax = nums[firstIndex+1];
    int maxPath = max(prevMax, currentMax);

    for(int i=firstIndex+2; i<nums.size()-leftIndex; i++)
    {
        maxPath = max(maxPath, nums[i]+prevMax);
        prevMax = max(prevMax, currentMax);
        currentMax = maxPath;
    }

    return maxPath;
}

int houseRobber(vector<int>&nums)
{
    if(nums.size()==1)
    {
        return nums[0];
    }

    if(nums.size()==2)
    {
        return max(nums[0], nums[1]);
    }
    
    int ans1 = solve(nums, 0, 1);
    int ans2 = solve(nums, 1, 0);
    return max(ans1, ans2);
}

int main()
{
    int n;
    cout<<"Enter size : ";
    cin>>n;
    vector<int>arr;

    for(int i=0; i<n; i++)
    {
        int a;
        cin>>a;
        arr.push_back(a);
    }

    int ans = houseRobber(arr);
    cout<<ans<<endl;
}