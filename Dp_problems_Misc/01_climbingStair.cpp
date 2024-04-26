//https://leetcode.com/problems/climbing-stairs/description/
#include <bits/stdc++.h>
using namespace std;


//Without space Tabulation approach
int climbingStairTabulationWithoutSpace(int n)
{
    int prev = 1;
    int prev2 = 1;
    int ans = 0;

    for (int i = 2; i <= n; i++)
    {
        ans = prev + prev2;
        prev = prev2;
        prev2 = ans;
    }
    return ans;
}

//With space Tabulation approach
int climbingStairTabulationWithSpace(int n, vector<int> &dp)
{
    dp[0] = dp[1] = 1;
    for (int i = 2; i <= n; i++)
        dp[i] = dp[i - 1] + dp[i - 2];
    return dp[n];
}

//Memoization approach
int climbingStairMemoization(int i, int n, vector<int> &dp)
{
    if (i == n)
        return dp[i] = 1;
    if (i > n)
        return dp[i] = 0;
    if (dp[i] != -1)
        return dp[i];
    int foronestep = climbingStairMemoization(i + 1, n, dp);
    int fortwostep = climbingStairMemoization(i + 2, n, dp);

    return dp[i] = foronestep + fortwostep;
}


//Recursion approach
int climbingStairRecursion(int i, int n)
{
    if (i == n)
        return 1;
    if (i > n)
        return 0;
    int foronestep = climbingStairRecursion(i + 1, n);
    int fortwostep = climbingStairRecursion(i + 2, n);

    return foronestep + fortwostep;
}

int main()
{
    int n = 5;
    cout << "Recursion solution"<< "\n";
    cout << climbingStairRecursion(0, n) << "\n";
    vector<int> dp(n, -1);
    cout << "Memoization solution"<< "\n";
    cout << climbingStairMemoization(0, n, dp) << "\n";
    cout << "Tabulation with space "<< "\n";
    cout << climbingStairTabulationWithSpace(n, dp)<<"\n";
    cout << "Tabulation solution without space "<< "\n";
    cout << climbingStairTabulationWithoutSpace(n) << "\n";

    return 0;
}