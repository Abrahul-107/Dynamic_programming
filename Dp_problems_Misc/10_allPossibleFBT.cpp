#include<bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {};
    TreeNode(int data): val(data), left(nullptr), right(nullptr) {};
};

vector<vector<TreeNode*>> dp;

vector<TreeNode*> allPossibleFBT(int n)
{
    if (n % 2 == 0)
        return {};
    if (n == 1)
    {
        dp[1] = {new TreeNode()};
        return dp[1];
    }

    if (!dp[n].empty())
        return dp[n];

    vector<TreeNode*> ans;

    for (int i = 1; i < n; i += 2)
    {
        vector<TreeNode*> left = allPossibleFBT(i);
        vector<TreeNode*> right = allPossibleFBT(n - 1 - i);

        for (auto &l : left)
        {
            for (auto &r : right)
            {
                TreeNode *root = new TreeNode();
                root->left = l;
                root->right = r;
                ans.push_back(root);
            }
        }
    }
    return dp[n] = ans;
}

int main()
{
    int n;
    cin >> n;
    dp.assign(n + 1, {});

    vector<TreeNode*> ans = allPossibleFBT(n);

    return 0;
}
