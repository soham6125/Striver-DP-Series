#include <bits/stdc++.h>
int getMaxPathSum(vector<vector<int>> &a)
{
    int n = a.size(), m = a[0].size();
    vector<vector<int>> dp(n, vector<int>(m, 0));
    for (int i = 0; i < m; i++)
        dp[0][i] = a[0][i];
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int mx = dp[i - 1][j] + a[i][j];
            if (j - 1 >= 0)
                mx = max(mx, dp[i - 1][j - 1] + a[i][j]);
            if (j + 1 < m)
                mx = max(mx, dp[i - 1][j + 1] + a[i][j]);
            dp[i][j] = mx;
        }
    }
    return *max_element(dp[n - 1].begin(), dp[n - 1].end());
}