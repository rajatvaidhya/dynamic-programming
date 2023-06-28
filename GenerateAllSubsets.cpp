//Generate All Subsets

#include<bits/stdc++.h>
using namespace std;

void solve(vector<int>&nums, int index, vector<vector<int>>&ans, vector<int>&replica)
{
    if(index==nums.size())
    {
        ans.push_back(replica);
        return;
    }

    replica.push_back(nums[index]);
    solve(nums, index+1, ans, replica);
    replica.pop_back();
    solve(nums, index+1, ans, replica);
}

int main()
{
    int n;
    cout<<"Enter array size : ";
    cin>>n;
    vector<int>nums;

    cout<<"Enter array elements";

    for(int i=0; i<n; i++)
    {
        int a;
        cin>>a;
        nums.push_back(a);
    }

    vector<vector<int>>ans;
    vector<int>replicate;

    solve(nums, 0, ans, replicate);
    
    for(int i=0; i<ans.size(); i++)
    {
        for(int j=0; j<ans[i].size(); j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}