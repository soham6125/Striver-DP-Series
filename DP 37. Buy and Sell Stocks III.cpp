// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/

class Solution
{
public:
    int maxProfit(vector<int> &price)
    {
        int n = price.size();

        vector<int> suff_profit(n, 0), suff_mx(n, 0);
        suff_mx[n - 1] = price[n - 1];
        for (int i = n - 2; i >= 0; i--)
            suff_mx[i] = max(suff_mx[i + 1], price[i]);
        // suff_profit stores the maximum profit from index i to index (n-1)
        // it can be calculated by considering that we buy stock at price price[i] and sell at max price from index (i+1) to index (n-1)
        for (int i = n - 2; i >= 0; i--)
        {
            int curr = suff_mx[i + 1] - price[i];
            suff_profit[i] = max(suff_profit[i + 1], curr);
        }

        vector<int> pref_profit(n, 0), pref_mn(n, 0);
        pref_mn[0] = price[0];
        for (int i = 1; i < n; i++)
            pref_mn[i] = min(pref_mn[i - 1], price[i]);
        // pref_profit stores the maximum profit from index 0 to index i
        // it can be calculated by considering that we buy stock at min price from index 0 to index (i-1) and sell at price price[i]
        for (int i = 1; i < n; i++)
        {
            int curr = price[i] - pref_mn[i - 1];
            pref_profit[i] = max(pref_profit[i - 1], curr);
        }

        // to find ans just calculate max profit till index i and max profit after index i
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int res = pref_profit[i] + (i + 1 < n ? suff_profit[i + 1] : 0);
            ans = max(ans, res);
        }
        return ans;
    }
};