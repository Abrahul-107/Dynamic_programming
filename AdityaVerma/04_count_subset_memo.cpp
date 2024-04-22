#include<bits/stdc++.h>
using namespace std;

int subsetCheck(vector<vector<int>>&memo,int *arr,int sum,int ind)
{
    //if sum is 0 always we can find the subset
    if(sum==0)
        return 1;
    //check the conditon for first element of array
    if(ind==0)
        return sum == arr[0];
    
    //for overlapping subproblem
    if(memo[ind][sum]!=-1)
        return memo[ind][sum];

    //Not taking the element 
    int not_take= subsetCheck(memo,arr,sum,ind-1);
    int take = 0;


    //Taking the element
    if(arr[ind]<=sum)
        take = subsetCheck(memo,arr,sum-arr[ind],ind-1);

    //return the optimized one 
    return memo[ind][sum] = take + not_take;
    

}

int countSubsetSum(int *arr,int n,int sum) {
    //2D DP array for memoization
    vector<vector<int>> memo(n, vector<int>(sum + 1, -1));
    return subsetCheck(memo,arr,sum,n - 1);
}


int main()
{
    int arr[] = {2,3,5,6,8,10};
    int sum = 10;
    int n = sizeof(arr)/sizeof(arr[0]);

    int ans = countSubsetSum(arr,n,sum);
    cout<<ans;


    return 0;

}