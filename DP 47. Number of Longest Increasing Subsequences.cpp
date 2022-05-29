// https://leetcode.com/problems/number-of-longest-increasing-subsequence/

class Solution
{
public:
    int findNumberOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<pair<int, int>> dp(n);
        int mx = 0;
        for (int i = 0; i < n; i++)
        {
            dp[i] = {1, 1}; // {length of lis, number of lis}
            for (int j = 0; j < i; j++)
            {
                if (nums[i] > nums[j])
                {
                    if (dp[i].first < dp[j].first + 1)
                    {
                        dp[i] = {dp[j].first + 1, dp[j].second};
                    }
                    else if (dp[i].first == dp[j].first + 1)
                    {
                        dp[i] = {dp[i].first, dp[j].second + dp[i].second};
                    }
                }
            }
        }

        // find length of longest increasing subsequence
        for (auto it : dp)
            mx = max(mx, it.first);

        int ans = 0;
        for (auto it : dp)
        {
            if (it.first == mx)
                ans += it.second;
        }
        return ans;
    }
};