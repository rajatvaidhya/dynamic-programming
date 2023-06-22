//Number of Increasing Paths in Grid

#include<bits/stdc++.h>
using namespace std;

int mod = 1000000007;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int dfs(int x, int y, vector<vector<int>>&grid, vector<vector<int>>&dp)
{
    if(dp[x][y]!=-1)
    {
        return dp[x][y];
    }

    int ans = 1;

    for(int i=0; i<4; i++)
    {
        int nx = x+dx[i];
        int ny = y+dy[i];

        if(nx>=0 && ny>=0 && nx<grid.size() && ny<grid[0].size() && grid[x][y]<grid[nx][ny])
        {
            ans = (ans%mod + dfs(nx, ny, grid, dp)%mod)%mod;
        }
    }
    
    return dp[x][y] = ans%mod;
}

int countPaths(vector<vector<int>>& grid, int m, int n) {

    int count = 0;
    vector<vector<int>>dp(m, vector<int>(n,-1));

    for(int i=0; i<grid.size(); i++)
    {
        for(int j=0; j<grid[0].size(); j++)
        {
            count = (count%mod + dfs(i,j,grid,dp)%mod)%mod;
        }
    }

    return count%mod;
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

    cout<<countPaths(matrix,m,n)<<endl;
}