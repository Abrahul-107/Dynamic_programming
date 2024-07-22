//https://www.geeksforgeeks.org/problems/longest-alternating-subsequence5951/1
#include<bits/stdc++.h>
using namespace std;


int alternatingMaxLength(vector<int>&arr)
{
    int increase = 1;
    int decrease = 1;

    int n = arr.size();
    for(int i=1;i<n;i++)
    {
        if(arr[i]>arr[i-1])
            increase = decrease+1;
        if(arr[i]<arr[i-1])
            decrease = increase+1;        
    }
    return max(increase,decrease);
}

int main()
{
    vector<int>arr = {1, 17, 5, 10, 13, 15, 10, 5, 16, 8};
    int ans = alternatingMaxLength(arr);
    cout<<ans<<endl;

    return 0;
}