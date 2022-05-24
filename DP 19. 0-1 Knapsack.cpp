int knapsack(vector<int> w, vector<int> val, int n, int W)
{
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
    for (int i = 0; i <= W; i++)
        dp[0][i] = 0;
    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= W; j++)
        {
            if (w[i - 1] <= j)
            {
                dp[i][j] = max(val[i - 1] + dp[i - 1][j - w[i - 1]], dp[i - 1][j]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][W];
}

// Recursively
int helper(vector<vector<int>> &dp, vector<int> &w, vector<int> &val, int i, int sum)
{
    if (i >= w.size())
        return 0;
    if (sum == 0)
        return 0;
    if (dp[i][sum] != -1)
        return dp[i][sum];
    int res1 = helper(dp, w, val, i + 1, sum);
    int res2 = 0;
    if (w[i] <= sum)
        res2 = val[i] + helper(dp, w, val, i + 1, sum - w[i]);
    return dp[i][sum] = max(res1, res2);
}

int knapsack(vector<int> w, vector<int> val, int n, int W)
{
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, -1));
    return helper(dp, w, val, 0, W);
}