//https://leetcode.com/problems/best-team-with-no-conflicts/
#include<bits/stdc++.h>
using namespace std;

int bestTeamWithNoConflict(vector<int>&ages,vector<int>&scores)
{
    int n =scores.size();
    vector<pair<int,int>>arr;

    for(int i=0;i<n;i++)
        arr.push_back({ages[i],scores[i]});

    
    //Sort the array according to the age and score descendig order  
    sort(arr.begin(),arr.end(),greater<pair<int,int>>());
    //after sorting arr = [(2, 6), (2, 4), (1, 5), (1, 5)]

     int dp[1000];
    int ans = 0;
    memset(dp, 0, sizeof dp);
    for(int i=0;i<n;i++)
    {
        for(int j=i;j>=0;j--)
        {
            if(arr[i].second<=arr[j].second)
            {
                dp[i] = max(dp[i],dp[j]+arr[i].second);
                ans = max(ans,dp[i]);
            }
        }
    }
    return ans;

}
int main()
{
    vector<int>ages = {2,1,2,1};
    vector<int>scores = {4,5,6,5};
    cout<<bestTeamWithNoConflict(ages,scores);

    return  0;

}


/*

Let's break this down with the current arr:

arr = [(2, 6), (2, 4), (1, 5), (1, 5)]

i = 0: arr[0] = (2, 6)

j = 0: Since arr[0].second (6) <= arr[0].second (6), dp[0] = max(dp[0], dp[0] + 6) = 6.
ans = max(ans, dp[0]) = 6.
Intermediate dp: [6, 0, 0, 0]

i = 1: arr[1] = (2, 4)

j = 1: Since arr[1].second (4) <= arr[1].second (4), dp[1] = max(dp[1], dp[1] + 4) = 4.
j = 0: Since arr[1].second (4) <= arr[0].second (6), dp[1] = max(dp[1], dp[0] + 4) = 10.
ans = max(ans, dp[1]) = 10.
Intermediate dp: [6, 4, 0, 0] -> [6, 10, 0, 0]

i = 2: arr[2] = (1, 5)

j = 2: Since arr[2].second (5) <= arr[2].second (5), dp[2] = max(dp[2], dp[2] + 5) = 5.
j = 1: Since arr[2].second (5) > arr[1].second (4), no update.
j = 0: Since arr[2].second (5) <= arr[0].second (6), dp[2] = max(dp[2], dp[0] + 5) = 11.
ans = max(ans, dp[2]) = 11.
Intermediate dp: [6, 10, 11, 0]

i = 3: arr[3] = (1, 5)

j = 3: Since arr[3].second (5) <= arr[3].second (5), dp[3] = max(dp[3], dp[3] + 5) = 5.
j = 2: Since arr[3].second (5) <= arr[2].second (5), dp[3] = max(dp[3], dp[2] + 5) = 16.
j = 1: Since arr[3].second (5) > arr[1].second (4), no update.
j = 0: Since arr[3].second (5) <= arr[0].second (6), dp[3] = max(dp[3], dp[0] + 5) = 16.
ans = max(ans, dp[3]) = 16.
Final dp: [6, 10, 11, 16]
*/