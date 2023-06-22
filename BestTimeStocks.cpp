//Best Time to Buy and Sell Stocks

#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& arr) {

    int maxSum = 0;
    int minVal = INT_MAX;
    int n = arr.size();

    for(int i=0; i<n; i++)
    {
        if(minVal>arr[i])
        {
            minVal = arr[i];
        }
        else
        {
            maxSum = max(maxSum, arr[i]-minVal);
        }
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

    cout<<maxProfit(arr)<<endl;
}