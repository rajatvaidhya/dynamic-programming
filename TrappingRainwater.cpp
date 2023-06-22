//Trapping Rainwater 

#include<bits/stdc++.h>
using namespace std;

int trap(vector<int>& height) {

    int leftBuffer = INT_MIN;
    int rightBuffer = INT_MIN;
    int rightPreprocess[height.size()];
    int leftPreprocess[height.size()];
    int finalBuffer = 0;

    for(int i=0; i<height.size(); i++)
    {
        leftBuffer = max(leftBuffer, height[i]);
        leftPreprocess[i] = leftBuffer;
    }

    for(int i=height.size()-1; i>=0; i--)
    {
        rightBuffer = max(rightBuffer, height[i]);
        rightPreprocess[i] = rightBuffer;
    }

    for(int i=0; i<height.size(); i++)
    {
        finalBuffer += min(leftPreprocess[i], rightPreprocess[i]) - height[i];
    }

    return finalBuffer;
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

    cout<<trap(arr)<<endl;
}