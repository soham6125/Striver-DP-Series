int countPartitions(int n, int d, vector<int> &arr)
{
    int sum = 0;
    for (auto &it : arr)
        sum += it;
    if (d > sum or (sum + d) % 2)
        return 0;
    int x = (sum + d) / 2;
    vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));
    int mod = 1e9 + 7;
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= x; j++)
        {
            if (j >= arr[i - 1])
                dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - arr[i - 1]]) % mod;
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][x];
}
