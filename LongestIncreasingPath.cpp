//Longest Increasing Path in a Matrix

#include<bits/stdc++.h>
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int dfs(int x, int y, vector<vector<int>>&mat, vector<vector<int>>&dp)
{
    if(dp[x][y]!=-1)
    {
        return dp[x][y];
    }

    int ans = 0;

    for(int i=0; i<4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx>=0 && ny>=0 && nx<mat.size() && ny<mat[0].size() && mat[x][y]<mat[nx][ny])
        {
            ans = max(ans, dfs(nx, ny, mat, dp));
        }
    }
    
    return dp[x][y] = ans+1;
}

int longestIncreasingPath(vector<vector<int>>& matrix, int m, int n) {
    int count = 0;

    vector<vector<int>>dp(m, vector<int>(n, -1));

    for(int i=0; i<matrix.size(); i++)
    {
        for(int j=0; j<matrix[0].size(); j++)
        {
            count = max(count, dfs(i,j,matrix,dp));
        }
    }

    return count;
}

int main()
{
    int m,n;
    cin>>m>>n;

    vector<vector<int>>matrix(m, vector<int>(n));

    for(int i=0; i<m; i++)
    {
        vector<int>arr;

        for(int j=0; j<n; j++)
        {
            int a;
            cin>>a;
            arr.push_back(a);
        }

        matrix.push_back(arr);
    }

    cout<<longestIncreasingPath(matrix,m,n)<<endl;
}