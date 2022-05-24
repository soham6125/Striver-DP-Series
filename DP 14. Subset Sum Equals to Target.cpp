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

// Recursively
bool helper(vector<int> &a, vector<vector<int>> &dp, int i, int sum, int tar)
{
    if (i == a.size() or sum >= tar)
        return (sum == tar);
    if (dp[i][sum] != -1)
        return dp[i][sum];
    if (a[i] + sum > tar)
    {
        bool res1 = helper(a, dp, i + 1, sum, tar);
        return dp[i][sum] = res1;
    }
    else
    {
        bool res1 = helper(a, dp, i + 1, sum, tar);
        bool res2 = helper(a, dp, i + 1, sum + a[i], tar);
        return dp[i][sum] = (res1 || res2);
    }
}

bool subsetSumToK(int n, int sum, vector<int> &arr)
{
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));
    return helper(arr, dp, 0, 0, sum);
}