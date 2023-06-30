//Triangle - Minimum path sum

#include<bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>>&triangle, int i, int j, vector<vector<int>>&dp)
{
    if(i==triangle.size()-1) return triangle[i][j];
    if(dp[i][j]!=-1) return dp[i][j];
    int down = triangle[i][j] + solve(triangle, i+1, j, dp);
    int bottomRight = triangle[i][j] + solve(triangle, i+1, j+1, dp);
    return dp[i][j] = min(down, bottomRight);
}

int minimumTotal(vector<vector<int>>& triangle) {

    vector<vector<int>>dp;

    for(int i=0; i<triangle.size(); i++)
    {
        vector<int>vect(i+1, -1);
        dp.push_back(vect);
    }

    return solve(triangle, 0, 0, dp);
}

int main()
{
    int n;
    cout<<"Enter size : ";
    cin>>n;

    vector<vector<int>>tri;

    cout<<"Enter elements"<<endl;

    for(int i=1; i<=n; i++)
    {
        vector<int>vect;

        for(int j=0; j<i; j++)
        {
            int a;
            cin>>a;
            vect.push_back(a);
        }

        tri.push_back(vect);
    }

    cout<<minimumTotal(tri)<<endl;
}