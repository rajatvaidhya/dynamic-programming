//Maximum Product Subarray

#include<bits/stdc++.h>
using namespace std;

int maxProduct(vector<int>& nums) {

    int maxProduct = INT_MIN;
    int product = 1;

    for(int i=0; i<nums.size(); i++)
    {
        product = product*nums[i];
        maxProduct = max(maxProduct,product);

        if(product==0)
        {
            product=1;
        }
    }

    product = 1;

    for(int i=nums.size()-1; i>=0; i--)
    {
        product = product*nums[i];
        maxProduct = max(maxProduct,product);

        if(product==0)
        {
            product=1;
        }
    }

    return maxProduct;
    
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

    cout<<maxProduct(arr)<<endl;
}