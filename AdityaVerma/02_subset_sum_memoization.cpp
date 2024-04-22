#include<bits/stdc++.h>
using namespace std;

bool subsetCheck(vector<vector<int>>&memo,int *arr,int sum,int ind)
{
    //if sum is 0 always we can find the subset
    if(sum==0)
        return true;
    //check the conditon for first element of array
    if(ind==0)
        return sum == arr[0];
    
    //for overlapping subproblem
    if(memo[ind][sum]!=-1)
        return memo[ind][sum];

    //Not taking the element 
    bool not_take= subsetCheck(memo,arr,sum,ind-1);
    bool take = 0;


    //Taking the element
    if(arr[ind]<=sum)
        take = subsetCheck(memo,arr,sum-arr[ind],ind-1);

    //return the optimized one 
    return memo[ind][sum] = take || not_take;
    

}

bool subsetSumToK(int *arr,int n,int sum) {
    //2D DP array for memoization
    vector<vector<int>> memo(n, vector<int>(sum + 1, -1));
    return subsetCheck(memo,arr,sum,n - 1);
}


int main()
{
    int arr[] = {10, 12, 3, 14};
    int sum = 15;
    int n = 4;

    if (subsetSumToK(arr,n,sum))
        cout << "Subset  found";
    else
        cout << "Subset  not found";

    return 0;

}