//https://www.geeksforgeeks.org/problems/find-optimum-operation4504/1
#include<bits/stdc++.h>
using namespace std;

/*8 

1 2 4 8   
n = 5

Started from 1 
if (i % 2 == 0) 
    dp[i] = dp[i / 2] + 1;
else 
    dp[i] = dp[i - 1] + 1;
        

dp = {0,0,0,0,0,0}
dp = {0,1,2,3,3,4}

*/  

int minOperationToReachN(int n)
{
    int result = 0;
    while (n > 0) 
    {
        if (n % 2 == 0) 
            n /= 2;
        else 
            n -= 1;
        result++;
    }
    return result;
}
int main()
{
    int n;
    cin>>n;

    cout<<minOperationToReachN(n);

    return 0;
}