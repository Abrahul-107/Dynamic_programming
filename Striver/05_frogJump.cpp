/*Problem statement

There is a frog on the '1st' step of an 'N' stairs long staircase. The frog wants to reach the 'Nth' stair.
'HEIGHT[i]' is the height of the '(i+1)th' stair.If Frog jumps from 'ith' to 'jth' stair, the energy lost in
the jump is given by absolute value of ( HEIGHT[i-1] - HEIGHT[j-1] ). If the Frog is on 'ith' staircase,
he can jump either to '(i+1)th' stair or to '(i+2)th' stair. Your task is to find the minimum total energy
used by the frog to reach from '1st' stair to 'Nth' stair.

For Example
If the given ‘HEIGHT’ array is [10,20,30,10], the answer 20 as the frog can jump from 1st stair to 2nd stair
(|20-10| = 10 energy lost) and then a jump from 2nd stair to last stair (|10-20| = 10 energy lost).
So, the total energy lost is 20.

Sample Input 1:
2
4
10 20 30 10
3
10 50 10
Sample Output 1:
20
0

Sample Input 2:
2
8
7 4 4 2 6 6 3 4
6
4 8 3 10 4 4
Sample Output 2:
7
2
*/
#include <bits/stdc++.h>
using namespace std;

// Recursive solution
int frogJumpRecursion(vector<int> &heights, int n)
{
    if (n == 0)
        return 0;
    int forTwoStep = INT_MAX;

    int foroneStep = frogJumpRecursion(heights, n - 1) + abs(heights[n] - heights[n - 1]);
    if (n > 1)
        forTwoStep = frogJumpRecursion(heights, n - 2) + abs(heights[n] - heights[n - 2]);

    return min(foroneStep, forTwoStep);
}

int frogJumpMemoizationHelper(vector<int> &heights, int n, vector<int> &dp)
{
    if (n == 0)
        return 0;
    if (dp[n] != -1)
        return dp[n];

    int forTwoStep = INT_MAX;

    int foroneStep = frogJumpMemoizationHelper(heights, n - 1, dp) + abs(heights[n] - heights[n - 1]);
    if (n > 1)
        forTwoStep = frogJumpMemoizationHelper(heights, n - 2, dp) + abs(heights[n] - heights[n - 2]);

    return dp[n] = min(foroneStep, forTwoStep);
}

// Memoization solution
int frogJumpMemoization(vector<int> &heights, int n)
{
    vector<int> dp(n + 1, -1);
    return frogJumpMemoizationHelper(heights, n, dp);
}

//Tabulation solution
int frogJumpTabulation(vector<int> &heights, int n)
{
    int previous1 = 0;
    int previous2 = 0;

    for (int i = 1; i < n; i++)
    {
        int jump2 = INT_MAX;
        int jump1 = previous1 + abs(heights[i] - heights[i - 1]);
        if (i > 1)
            jump2 = previous2 + abs(heights[i] - heights[i - 2]);

        int curr = min(jump1, jump2);

        previous2 = previous1;
        previous1 = curr;
    }
    return previous1;
}
int main()
{
    vector<int> heights = {7, 4, 4, 2, 6, 6, 3, 4};
    int n = heights.size();
    cout<<n<<endl;
    // cout << frogJumpRecursion(heights, n - 1);
    // cout << frogJumpMemoization(heights, n - 1);
    cout << frogJumpTabulation(heights, n );

    return 0;
}