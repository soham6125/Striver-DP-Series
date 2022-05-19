int frogJump(int n, vector<int> &a)
{
    vector<long long> dp(n);
    dp[0] = 0;
    for (int i = 1; i < n; i++)
    {
        dp[i] = min(dp[i - 1] + abs(a[i] - a[i - 1]), dp[i - 2] + abs(a[i] - a[i - 2]));
    }
    return dp[n - 1];
}