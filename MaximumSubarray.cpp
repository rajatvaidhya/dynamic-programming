//Maximum Subarray

#include<bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int>& nums) {

    int currSum = 0;
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

    return maxSum;
    
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

    cout<<maxSubArray(arr)<<endl;
}