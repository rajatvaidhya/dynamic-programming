//Fair Distribution of Cookies - (Recursion, Backtracking)

#include<bits/stdc++.h>
using namespace std;

int ans = INT_MAX;

void solve(int index, vector<int>&cookies, vector<int>&child, int k)
{
    if(index>=cookies.size())
    {
        int unfair = *max_element(child.begin(),child.end());
        ans = min(ans, unfair);
        return;
    }

    for(int i=0; i<k; i++)
    {
        child[i] = child[i]+cookies[index];
        solve(index+1, cookies, child, k);
        child[i] = child[i]-cookies[index];
    }
}

int distributeCookies(vector<int>& cookies, int k) {

    vector<int>child(k,0);
    solve(0, cookies, child, k);
    return ans;
}

int main()
{
    int n,k;
    cout<<"Enter size : ";
    cin>>n;
    vector<int>cookies;

    cout<<"Enter elements"<<endl;

    for(int i=0; i<n; i++)
    {
        int a;
        cin>>a;
        cookies.push_back(a);
    }

    cout<<"Enter number of childs : ";
    cin>>k;

    cout<<distributeCookies(cookies, k);
}