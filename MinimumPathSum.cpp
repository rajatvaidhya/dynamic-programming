//Minimum Path Sum

#include<bits/stdc++.h>
using namespace std;

int dx[2] = {1, 0};
int dy[2] = {0, 1};

int solve(vector<vector<int>>&grid, int m, int n)
{
    if(m>=grid.size()-1 && n>=grid[0].size()-1)
    {
        return grid[m][n];
    }

    int ans = INT_MAX;

    for(int i=0; i<2; i++)
    {
        int nx = n+dx[i];
        int ny = m+dy[i];
        int res = grid[m][n];

        if(nx>=0 && ny>=0 && nx<grid[0].size() && ny<grid.size())
        {
            res = res + solve(grid, ny, nx);
            ans = min(ans, res);
        }
    }

    return ans;
}

int minPathSum(vector<vector<int>>& grid) {

    int m=0,n=0;
    return solve(grid, m, n);
}

int main()
{
    int m,n;
    cout<<"Enter m : ";
    cin>>m;
    cout<<"Enter n : ";
    cin>>n;

    vector<vector<int>>mat(m);


    for(int i=0; i<m; i++)
    {
        vector<int>vect;

        for(int j=0; j<n; j++)
        {
            int a;
            cin>>a;
            vect.push_back(a);
        }

        mat[i] = vect;
    }

    cout<<minPathSum(mat)<<endl;
}