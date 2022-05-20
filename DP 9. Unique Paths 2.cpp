int mazeObstacles(int m, int n, vector<vector<int>> &mat)
{
    vector<vector<int>> dp(m, vector<int>(n, 0));
    int mod = 1000000007;
    dp[0][0] = 1 - mat[0][0];
    for (int i = 1; i < m; ++i)
    {
        if (mat[i][0] == 0)
            dp[i][0] = dp[i - 1][0];
        else
            dp[i][0] = 0;
    }
    for (int i = 1; i < n; ++i)
    {
        if (mat[0][i] == 0)
            dp[0][i] = dp[0][i - 1];
        else
            dp[0][i] = 0;
    }
    for (int i = 1; i < m; ++i)
    {
        for (int j = 1; j < n; ++j)
        {
            if (mat[i][j] == 0)
                dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % mod;
            else
                dp[i][j] = 0;
        }
    }
    return dp[m - 1][n - 1];
}