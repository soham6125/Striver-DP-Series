// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/

class Solution
{
public:
    int maxProfit(int k, vector<int> &price)
    {
        int n = price.size();
        if (n == 0)
            return 0;
        int profit[k + 1][n + 1];
        for (int i = 0; i <= k; i++)
            profit[i][0] = 0;
        for (int j = 0; j <= n; j++)
            profit[0][j] = 0;
        for (int i = 1; i <= k; i++)
        {
            for (int j = 1; j < n; j++)
            {
                int max_so_far = INT_MIN;
                for (int m = 0; m < j; m++)
                    max_so_far = max(max_so_far, price[j] - price[m] + profit[i - 1][m]);
                profit[i][j] = max(profit[i][j - 1], max_so_far);
            }
        }
        int ans = profit[k][n - 1];
        return ans;
    }
};