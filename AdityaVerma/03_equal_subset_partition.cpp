/*Memoization approch */
/*Leetcode 416*/

#include<bits/stdc++.h>
using namespace std;

bool helper(vector<vector<int>>&memo,int *arr,int n,int sum)
{
    if(sum==0)
        return true;
    if(n==0)
        return arr[n] == sum;
    
    if(memo[n][sum]!=-1)
        return memo[n][sum];
    
    bool not_take = helper(memo,arr,n-1,sum);
    bool take = 0;

    if(arr[n]<=sum)
    take = helper(memo,arr,n-1,sum-arr[n]);

    return memo[n][sum] = take|| not_take;



}
bool equalPartitionSubsetSum(int *arr,int n,int sum)
{
    vector<vector<int>> memo(n, vector<int>(sum + 1, -1));
    return helper(memo,arr,n-1,sum);

}



int main()
{
    int arr[] = {10, 12, 3, 23};
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