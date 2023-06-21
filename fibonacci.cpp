//Fibonacci Series through Memoization

#include<bits/stdc++.h>
using namespace std;

int fibonacci(int n, vector<int>&dp)
{
    if(dp[n]!=-1)
    {
        return dp[n];
    }

    int P1 = fibonacci(n-1, dp);
    int P2 = fibonacci(n-2, dp);

    dp[n] = P1+P2;
    return P1+P2;
}

int main()
{
    int n;
    cout<<"Enter index : ";
    cin>>n;
    vector<int>dp(n+1, -1);
    dp[0] = 0;
    dp[1] = 1;

    cout<<"The fibonacci term at "<<n<<"th index is : "<<fibonacci(n, dp)<<endl;
}



//Fibonacci (Tabulation - Space Optimised)

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout<<"Enter index : ";
    cin>>n;

    int prev2 = 0;
    int prev = 1;
    int curr = 0;

    for(int i=2; i<=n; i++)
    {
        curr = prev2 + prev;
        prev2 = prev;
        prev = curr;
    }

    cout<<curr<<endl;
}