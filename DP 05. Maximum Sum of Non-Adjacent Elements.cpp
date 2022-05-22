int maximumNonAdjacentSum(vector<int> &a)
{
    int n = a.size();
    if (n == 1)
        return a[0];
    if (n == 2)
        return max(a[0], a[1]);
    vector<long long> dp(n, 0);
    dp[0] = a[0];
    dp[1] = max(a[0], a[1]);
    long long ans = 0;
    for (int i = 2; i < n; i++)
    {
        dp[i] = max(dp[i - 2] + a[i], dp[i - 1]);
        ans = max(ans, dp[i]);
    }
    return ans;
}