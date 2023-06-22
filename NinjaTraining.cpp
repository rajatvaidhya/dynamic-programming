//Ninja Training with Memoization, Tabulation 

#include<bits/stdc++.h>
using namespace std;

int ninja(vector<vector<int>>&arr, int day, int last, vector<vector<int>>&dp)
{
    if(day==0)
    {
        int maxi = INT_MIN;

        for(int i=0; i<3; i++)
        {
            if(i!=last)
            {
                maxi = max(maxi, arr[0][i]);
            }
        }

        return maxi;
    }

    if(dp[day][last]!=-1)
    {
        return dp[day][last];
    }

    int maxi = INT_MIN;

    for(int i=0; i<3; i++)
    {
        int maxPoints = INT_MIN;

        if(i!=last)
        {
            maxPoints = arr[day][i] + ninja(arr, day-1, i, dp);
        }

        maxi = max(maxi, maxPoints);
    }

    return dp[day][last] = maxi;
}



//Tabulation (Space Optimised)

int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>>dp(n, vector<int>(4, -1));

    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][0], points[0][1]);
    dp[0][3] = max(points[0][0], max(points[0][1], points[0][2]));

    for(int day=1; day<n; day++)
    {
        for(int last=0; last<4; last++)
        {
            int maxi = 0;
            
            for(int task=0; task<3; task++)
            {
                if(task!=last)
                {
                    int point = points[day][task] + dp[day-1][task];
                    maxi = max(maxi, point);
                }
            }

            dp[day][last] = maxi;
        }
    }

    return dp[n-1][3];
}

int main()
{
    int n;
    cout<<"Enter size : ";
    cin>>n;
    vector<vector<int>>arr(n, vector<int>(3));
    vector<vector<int>>dp(n, vector<int>(4, -1));

    for(int i=0; i<n; i++)
    {
        vector<int>vect;

        for(int j=0; j<3; j++)
        {
            int a;
            cin>>a;
            vect.push_back(a);
        }

        arr[i] = vect;
    }

    cout<<ninja(arr, n-1, 3, dp)<<endl;
}