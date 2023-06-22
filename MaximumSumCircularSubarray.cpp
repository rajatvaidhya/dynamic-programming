//Maximum Sum Circular Subarray

#include<bits/stdc++.h>
using namespace std;

int maxSubarraySumCircular(vector<int>& nums) {

    int minSum = INT_MAX;
    int sum = 0;
    int negValues = 0;
    int currSum = 0;

    for(int i=0; i<nums.size(); i++)
    {
        if(nums[i]<0)
        {
            negValues++;
        }
    }

    if(negValues == nums.size())
    {
        int maxAns = INT_MIN;
        
        for(int i=0; i<nums.size(); i++)
        {
            maxAns = max(maxAns, nums[i]);
        }

        return maxAns;
    }

    for(int i=0; i<nums.size(); i++)
    {
        sum = sum + nums[i];
    }

    for(int i=0; i<nums.size(); i++)
    {
        currSum = currSum + nums[i];

        if(currSum > nums[i])
        {
            currSum = nums[i];
        }

        minSum = min(minSum, currSum);
    }

    currSum = 0;
    int maxSum = INT_MIN;

    for(int i=0; i<nums.size(); i++)
    {
        currSum = currSum + nums[i];

        if(currSum < nums[i])
        {
            currSum = nums[i];
        }

        maxSum = max(maxSum, currSum);
    }

    cout<<"MinSum : "<<minSum<<endl;
    cout<<maxSum<<endl;
    
    return max((sum - minSum),maxSum);
    
}

int main()
{
    int n;
    cin>>n;
    vector<int>arr;

    for(int i=0; i<n; i++)
    {
        int a;
        cin>>a;
        arr.push_back(a);
    }

    cout<<maxSubarraySumCircular(arr)<<endl;
}