#include <bits/stdc++.h>
using namespace std;

int knapSack(int w[], int v[], int cap, int n)
{
    if (cap == 0 || n == 0)
        return 0;

    if (w[n - 1] <= cap)
    {
        return max((v[n - 1] + knapSack(w, v, cap - w[n - 1], n - 1)), knapSack(w, v, cap, n - 1));
    }
    else
        return knapSack(w, v, cap, n - 1);
}


int main()
{
    int value[] = {3, 4, 5, 7, 8};
    int weight[] = {2, 3, 6, 7, 5};
    int maxcap = 11;

    cout << knapSack(weight,value,maxcap,5);

    return 0;
}
