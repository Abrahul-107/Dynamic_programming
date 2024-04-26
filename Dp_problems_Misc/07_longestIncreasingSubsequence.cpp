//https://leetcode.com/problems/longest-increasing-subsequence/description/
#include<bits/stdc++.h>
using namespace std;

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
    cout<<longestIncreasingSubsequence(v)<<endl;

    return 0;

}