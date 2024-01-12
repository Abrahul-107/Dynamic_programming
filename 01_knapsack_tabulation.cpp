#include <bits/stdc++.h>
using namespace std;

int knapSackTabulation(int w[], int v[], int maxi, int n)
{
    vector<int> dp(maxi + 1, 0);
    for (int i = 0; i < n; i++)
    {
        for (int weight = maxi; weight >= w[i]; weight--)
        {
            dp[weight] = max(dp[weight], dp[weight - w[i]] + v[i]);
        }
    }
    return dp[maxi];
}

int main()
{
    int value[] = {3, 4, 5, 7, 8};
    int weight[] = {2, 3, 6, 7, 5};
    int maxcap = 11;

    cout << knapSackTabulation(weight, value, maxcap, 5) << endl;

    return 0;
}
