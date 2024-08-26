/* OM NAMAH SIVAYA */
/*subset sum (Knapsack variation)*/
#include<bits/stdc++.h>
using namespace std;

bool isSubsetPossible(int *arr, int n, int sum) {
    // Initialize the tabulation array
    bool tab[n+1][sum+1];

    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= sum; j++) {
            // If the arr[i] is empty then we cannot find any sum here, so we have to mark it as false
            if(i == 0)
                tab[i][j] = false;
            // If the sum is 0, then it can always take an empty subset, so we return true here
            if(j == 0)
                tab[i][j] = true;
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= sum; j++) {
            // If arr[i-1] is less than or equal to sum, then we perform the following specific operation
            if(arr[i-1] <= sum)
                tab[i][j] = tab[i-1][j-arr[i-1]] || tab[i-1][j]; // Take || not take
            else
                tab[i][j] = tab[i-1][j]; // Else leave it as before
        }
    }
    //for better understanding 
    // for (int i=1;i<=n;i++)
    // {
    //     for(int j=1;j<=sum;j++)
    //     {
    //         cout<<tab[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    return tab[n][sum]; // Return the optimized answer
}

int main() {
    int n; cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int sum; cin >> sum;

    isSubsetPossible(arr, n, sum) ? cout << "Yes\n" : cout << "No\n";
    return 0;
}
