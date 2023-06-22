//Unique Paths

#include<bits/stdc++.h>
using namespace std;

int uniquePaths(int m, int n) {

    vector<vector<int>>vect(m, vector<int>(n,1));

    for(int i=1; i<m; i++)
    {
        for(int j=1; j<n; j++)
        {
            vect[i][j] = vect[i-1][j] + vect[i][j-1];
        }
    }

    return vect[m-1][n-1]; 
}

int main()
{
    int m,n;
    cin>>m,n;
    cout<<uniquePaths(m,n)<<endl;
}