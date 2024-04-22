/*Tabulation approch */
/*Leetcode 416*/

#include<bits/stdc++.h>
using namespace std;

bool equalPartitionSubsetSum(int *arr,int n,int sum)
{
    bool tab[n+1][sum+1];

    /*for first edge cases */
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=sum;j++)
        {
            if(i==0)
                tab[i][j] = false;
            if(j==0)
                tab[i][j] = true;
        }
    }

    // i denotes the size of the array 
    // j denotes the target sum (subset sum)
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            if(arr[i-1]<=j)
            tab[i][j] = tab[i-1][j-arr[i-1]] || tab[i-1][j];
            else 
            tab[i][j] = tab[i-1][j];

        }
    }

    return tab[n][sum];
}



int main()
{
    int arr[] = {10, 12, 3, 25};
    int n = 4;
    int sum = 0;

    for (int i = 0; i < n; i++)
        sum += arr[i];
    
    
    if(sum%2!=0)
        cout<<"Not possible";
    else
    equalPartitionSubsetSum(arr, n,sum/2) ? cout << "Yes\n" : cout << "No\n";
    return 0;
}