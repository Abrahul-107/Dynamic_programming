#include<bits/stdc++.h>
using namespace std;

int uniquePathObstacle(int i,int j,int m,int n,vector<vector<int>>og,int dp[501][501])
{
    if(dp[i][j]!=-1)   return dp[i][j];  //For overlap the size of matrix
    if(i>=m || j>=n) return dp[i][j]=0; //If reaches the final position then it find a single way so return 1
    if(i==m-1 && j==n-1) return dp[i][j]=1;  //For handling the overlapping subproblem
    if(og[i][j]==1) return 0;

    int forDown = uniquePathObstacle(i+1,j,m,n,og,dp); //For Down way   
    int forRight = uniquePathObstacle(i,j+1,m,n,og,dp); //For right way

    return dp[i][j]= forRight + forDown;


}


int main()
{
    vector<vector<int>> obstacleGrid = {{0,0,0},{0,1,0},{0,0,0}};
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    int dp[501][501];
    memset(dp, -1, sizeof(dp));
    cout<<uniquePathObstacle(0,0,m,n,obstacleGrid,dp);


    return 0;


}