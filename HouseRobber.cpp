//House Robber (Tabulation - Memory Optimised)

#include<bits/stdc++.h>
using namespace std;

int houseRobber(vector<int>&nums)
{
    if(nums.size()==1)
    {
        return nums[0];
    }

    int prevMax = nums[0];
    int currentMax = nums[1];
    int maxPath = max(prevMax, currentMax);

    for(int i=2; i<nums.size(); i++)
    {
        maxPath = max(maxPath, nums[i]+prevMax);
        prevMax = max(prevMax, currentMax);
        currentMax = maxPath;
    }

    return maxPath;
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