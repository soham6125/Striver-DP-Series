class Solution
{
public:
    int subsetSum(vector<int> &nums, int n, int sum, int count0)
    {
        int dp[n + 1][sum + 1];

        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= sum; j++)
            {
                if (i == 0)
                    dp[i][j] = 0;
                if (j == 0)
                    dp[i][j] = 1;
            }
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= sum; j++)
            {
                //                 to handle cases with 0s in nums
                if (nums[i - 1] <= j && nums[i - 1] != 0)
                    dp[i][j] = dp[i - 1][j - nums[i - 1]] + dp[i - 1][j];
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        return pow(2, count0) * dp[n][sum];
    }

    int findTargetSumWays(vector<int> &nums, int target)
    {
        int n = nums.size();
        int sum = 0;
        int count0 = 0;
        for (int x : nums)
        {
            sum += x;
            if (x == 0)
                count0++;
        }
        if ((sum + target) % 2 || sum < abs(target))
            return 0;
        int sum = (sum + target) / 2;
        return subsetSum(nums, n, sum, count0);
    }
};