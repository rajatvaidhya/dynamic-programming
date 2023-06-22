//Jump Game

#include<bits/stdc++.h>
using namespace std;

bool canJump(vector<int>& nums) {
    
    int steps = nums[0];
    int maxReach = nums[0];
    
    if(nums.size()==1)
    {
        return 1;
    }
    
    if(nums[0]==0)
    {
        return 0;
    }
    
    for(int i=1; i<nums.size(); i++)
    {
        if(i>=nums.size()-1)
        {
            return 1;
        }
        
        maxReach = max(maxReach, nums[i]+i);
        steps--;
        
        if(steps==0)
        {
            if(i>=maxReach)
            {
                return 0;
            }
            
            steps = maxReach - i;
        }
    }
    
    return 0;
    
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

    cout<<canJump(arr)<<endl;
}