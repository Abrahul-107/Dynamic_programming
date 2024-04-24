#include<bits/stdc++.h>
using namespace std;

//Tabulation solution
int uniquePathTabulation(int m,int n)
{
    int dp[101][101];
    memset(dp,0,sizeof dp);
    dp[m-1][n-1] = 1;

    for(int i=m-1;i>=0;i--)
    {
        for(int j=n-1;j>=0;j--)
        {
            if(i==m-1 && j==n-1)
                continue;
            dp[i][j] = dp[i+1][j] + dp[i][j+1];
            
        }
    }
    return dp[0][0];
    
}

//Memoization solution
int uniquePathMemoization(int i,int j,int m,int n,int dp[101][101])
{
    if(i==m && j==n)
        return 1;
    if(i>m || j>n)
        return 0;
    if(dp[i][j] != -1)
        return dp[i][j];
    
    int forDown = uniquePathMemoization(i,j+1,m,n,dp);
    int forRight = uniquePathMemoization(i+1,j,m,n,dp);

    return dp[i][j] = forDown + forRight;
}

//Recursion solution
int uniquePathRecursion(int i,int j,int m,int n)
{
    if(i>m || j>n)
        return 0;
    if(i==m && j==n)
        return 1;
    
    int forDown = uniquePathRecursion(i,j+1,m,n);
    int forRight = uniquePathRecursion(i+1,j,m,n);

    return forDown+forRight;
}


int main()
{
    int m = 3,n=7;
    cout<<"For recursion: "<<endl;
    cout<<uniquePathRecursion(1,1,m,n)<<endl;

    //For memoization
    int dp[101][101];
    memset(dp,-1,sizeof dp);
    cout<<"For memoization :"<<"\n";
    cout<<uniquePathMemoization(1,1,m,n,dp)<<endl;


    //For tabulation
    cout<<"Tabulation approch "<<"\n";
    cout<<uniquePathTabulation(m,n);


    return 0;

}