#include <bits/stdc++.h>
int ninjaTraining(int n, vector<vector<int>> &a)
{
    vector<vector<int>> dp(n, vector<int>(3, 0));
    dp[0][0] = a[0][0];
    dp[0][1] = a[0][1];
    dp[0][2] = a[0][2];
    int ans = max({dp[0][0], dp[0][1], dp[0][2]});
    for (int i = 1; i < n; i++)
    {
        dp[i][0] = max(dp[i - 1][1], dp[i - 1][2]) + a[i][0];
        dp[i][1] = max(dp[i - 1][0], dp[i - 1][2]) + a[i][1];
        dp[i][2] = max(dp[i - 1][1], dp[i - 1][0]) + a[i][2];
        ans = max({ans, dp[i][0], dp[i][1], dp[i][2]});
    }
    return ans;
}