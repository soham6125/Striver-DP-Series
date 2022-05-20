long long solve(vector<int> &a)
{
    int n = a.size();
    if (n == 1)
        return (long long)a[0];
    if (n == 2)
        return (long long)max(a[0], a[1]);
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

long long int houseRobber(vector<int> &v)
{
    int n = v.size();
    vector<int> v1, v2;
    if (n == 1)
        return (long long)v[0];
    for (int i = 0; i < n; i++)
    {
        if (i < n - 1)
            v1.push_back(v[i]);
        if (i > 0)
            v2.push_back(v[i]);
    }
    long long res1 = solve(v1);
    long long res2 = solve(v2);
    return max(res1, res2);
}