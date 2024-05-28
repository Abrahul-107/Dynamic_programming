/*https://leetcode.com/problems/minimum-path-sum/description/*/

#include <bits/stdc++.h>
using namespace std;

//Memoization code for minpath sum
int minPathSumMemoization(vector<vector<int>> &grid, int i, int j, int m, int n, vector<vector<int>> &dp)
{
    if (dp[i][j] != -1)
        return dp[i][j];

    if (i >= m || j >= n)
    {
        return INT_MAX;
    }
    if (i == m - 1 and j == n - 1)
        return dp[i][j] = grid[i][j];

    int col = minPathSumMemoization(grid, i + 1, j, m, n, dp);
    int row = minPathSumMemoization(grid, i, j + 1, m, n, dp);

    dp[i][j] = min(row, col) + grid[i][j];
    return dp[i][j];
}

//Tabulation code for minpath sum
int minPathSumTabulation(vector<vector<int>> &grid)
{

    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    dp[0][0] = grid[0][0];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!i && !j)
                continue;
            int down = INT_MAX, right = INT_MAX;
            if (i > 0)
                down = dp[i - 1][j];
            if (j > 0)
                right = dp[i][j - 1];
            dp[i][j] = grid[i][j] + min(down, right);
        }
    }
    return dp[n - 1][m - 1];
}

int main()
{
    vector<vector<int>> grid = {
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1}};

    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));

    int result = minPathSumMemoization(grid, 0, 0, m, n, dp);
    result = minPathSumTabulation(grid);
    cout << "The minimum path sum is: " << result << endl;

    return 0;
}