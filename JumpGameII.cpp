//Jump Game II

#include<bits/stdc++.h>
using namespace std;

int jump(vector<int>& nums) {

    int jumps = 0;
    int maxDist = 0;
    int currDist = 0;

    for(int i=0; i<nums.size()-1; i++)
    {
        maxDist = max(maxDist, nums[i]+i);
        
        if(currDist == i)
        {
            jumps++;
            currDist = maxDist;
        }
    }

    return jumps;
}

int main()
{
    int n;
    cin>>n;
    vector<int>vect;

    for(int i=0; i<n; i++)
    {
        int a;
        cin>>a;
        vect.push_back(a);
    }

    cout<<jump(vect)<<endl;
}