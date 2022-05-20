int minimumPathSum(vector<vector<int>> &a, int m)
{
    vector<vector<int>> dp(m, vector<int>(m, 1000000));
    dp[0][0] = a[0][0];
    for (int i = 1; i < m; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            int mn = a[i][j] + dp[i - 1][j];
            if (j - 1 >= 0)
                mn = min(mn, a[i][j] + dp[i - 1][j - 1]);
            dp[i][j] = mn;
        }
    }
    int res = 1000000000;
    for (int i = 0; i < a[m - 1].size(); i++)
        res = min(res, dp[m - 1][i]);
    return res;
}