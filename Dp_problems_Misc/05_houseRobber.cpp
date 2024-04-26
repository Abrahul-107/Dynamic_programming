//https://leetcode.com/problems/house-robber/description/
#include<bits/stdc++.h>
using namespace std;

int houseRobberTabulationWithNoSpace(vector<int>&v)
{
    int prev = v[0];
    int prev2 = 0;

    for(int i=1;i<v.size();i++)
    {
        int pick=0;
        if(i>1)
            pick = v[i]+ prev2;
        int notpick = prev;
        int curr = max(pick,notpick);
        prev2 = prev;
        prev = curr;

    }
    return prev;

}


int houseRobberTabulation(vector<int>&v,vector<int>&dp)
{
    if(v.size()==1)
        return v[0];
    dp[0] = v[0];
    dp[1] = max(v[0],v[1]);

    for(int i=2;i<v.size();i++)
        dp[i] = max(dp[i-1],dp[i-2]+ v[i]);

    return dp[v.size()-1]; 
}

int houseRobberMemoization(int i,vector<int>&v,vector<int>&dp)
{
    if(i>=v.size())
        return dp[i] = 0;
    int take  = v[i] + houseRobberMemoization(i+2,v,dp);
    int nottake = houseRobberMemoization(i+1,v,dp);

    return dp[i] = max(take,nottake);
}

int houseRobberRecursion(int i,vector<int>&v)
{
    if(i>=v.size())
        return 0;
    int take  = v[i] + houseRobberRecursion(i+2,v);
    int nottake = houseRobberRecursion(i+1,v);

    return max(take,nottake);
}

int main()
{
    vector<int>v = {2,7,9,3,1};
    int n = v.size();
    cout<<"Recursion solution"<<endl;
    cout<<houseRobberRecursion(0,v)<<endl;
    vector<int>dp(n+1,-1);
    cout<<"Memoization solution"<<endl;
    cout<<houseRobberMemoization(0,v,dp)<<endl;
    cout<<"Tabulation solution"<<endl;
    cout<<houseRobberTabulation(v,dp)<<endl;
    cout<<"Tabulation without space "<<endl;
    cout<<houseRobberTabulationWithNoSpace(v);

    return 0;

}