// https://leetcode.com/problems/distinct-subsequences/

int mod = 1e9 + 7;
int helper(string &t, string &s, int i, int j, vector<vector<int>> &dp)
{
    if (j < 0)
        return 1;
    if (i < 0)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    if (t[i] == s[j])
        return dp[i][j] = (helper(t, s, i - 1, j - 1, dp) + helper(t, s, i - 1, j, dp)) % mod;
    else
        return dp[i][j] = helper(t, s, i - 1, j, dp);
}

int subsequenceCounting(string &t, string &s, int lt, int ls)
{
    vector<vector<int>> dp(lt, vector<int>(ls, -1));
    return helper(t, s, lt - 1, ls - 1, dp);
}