//https://leetcode.com/problems/longest-increasing-subsequence/description/
#include<bits/stdc++.h>
using namespace std;

int LISRecursion(int ind,int prev,vector<int>&arr,int n,vector<vector<int>>&dp)
{
    if(ind==n)
        return 0;
    if(dp[ind][prev+1]!=-1)
        return dp[ind][prev+1];
    int len = 0 + LISRecursion(ind+1,prev,arr,n,dp);
    if(prev==-1 || arr[ind]>arr[prev])
        len = max(len,1+LISRecursion(ind+1,ind,arr,n,dp));
    return dp[ind][prev+1] = len;

}


int longestIncreasingSubsequence(vector<int>&arr)
{
    int n = arr.size();
    vector<int>dp(n,1);

    for(int i=1;i<n;i++)
        for(int j=0;j<i;j++)
            if(arr[i]>arr[j])
                dp[i] = max(dp[i],1+dp[j]);
    return *std::max_element(dp.begin(), dp.end());    
}

int main()
{
    vector<int>v = {10,2,4,3,1,45,0};
    int n = v.size();
    cout<<longestIncreasingSubsequence(v)<<endl;
    vector<vector<int>>dp(n,vector<int>(n+1,-1));

    cout<<LISRecursion(0,-1,v,n,dp);

    return 0;

}