int minSubsetSumDifference(vector<int> &arr, int n)
{
    int sum = 0;
    for (auto &it : arr)
        sum += it;
    bool dp[n + 1][sum + 1] = {-1};
    for (int i = 0; i <= sum; i++)
        dp[0][i] = false;
    for (int i = 0; i <= n; i++)
        dp[i][0] = true;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (arr[i - 1] > j)
            {
                dp[i][j] = dp[i - 1][j];
            }
            else if (arr[i - 1] <= j)
            {
                dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j];
            }
        }
    }
    for (int i = sum / 2; i >= 0; i--)
    {
        if (dp[n][i])
        {
            int diff = abs(i - (sum - i));
            return diff;
        }
    }
    return 0;
}
