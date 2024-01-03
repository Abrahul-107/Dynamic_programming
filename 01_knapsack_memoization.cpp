#include<bits/stdc++.h>
using namespace std;

int dp[100][100];


int knapSackMemo(int w[],int v[],int maxi,int n)
{
    if(n==0 || maxi==0)
       return 0;
    if(dp[n][maxi]!=-1)
        return dp[n][maxi];

    if(w[n-1]<=maxi)
        dp[n][maxi] = max(v[n-1]+knapSackMemo(w,v,maxi-w[n-1],n-1),knapSackMemo(w,v,maxi,n-1));
    else if(w[n-1]>maxi)
        dp[n][maxi]= knapSackMemo(w,v,maxi,n-1);

    return dp[n][maxi];
        
}

int main()
{
    int value[] = {3, 4, 5, 7, 8};
    int weight[] = {2, 3, 6, 7, 5};
    int maxcap = 11;
    memset(dp,-1,sizeof(dp));
    cout << knapSackMemo(weight,value,maxcap,5);

    return 0;
}