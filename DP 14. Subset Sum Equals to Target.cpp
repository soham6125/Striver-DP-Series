bool subsetSumToK(int n, int sum, vector<int> &arr)
{
    bool dp[n + 1][sum + 1] = {-1};

    // if n == 0 and sum > 0, result = false
    for (int i = 0; i <= sum; i++)
        dp[0][i] = false;
    // if sum == 0 and n >= 0, result = true
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
    return dp[n][sum];
}