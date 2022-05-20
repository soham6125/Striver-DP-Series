int minimumElements(vector<int> &num, int x)
{
    int n = num.size();
    vector<vector<long>> dp(n + 1, vector<long>(x + 1, 0));
    for (int i = 0; i <= x; i++)
    {
        dp[0][i] = INT_MAX;
    }
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= x; j++)
        {
            if (num[i - 1] > j)
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - num[i - 1]] + 1);
            }
        }
    }
    return (dp[n][x] == INT_MAX ? -1 : dp[n][x]);
}