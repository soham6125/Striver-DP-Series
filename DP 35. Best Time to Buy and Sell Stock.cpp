// https://www.codingninjas.com/codestudio/problems/stocks-are-profitable_893405?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos

#include <bits/stdc++.h>
int maximumProfit(vector<int> &prices)
{
    int mn = 1000000000, ans = 0;
    for (int i = 0; i < prices.size(); i++)
    {
        ans = max(ans, prices[i] - mn); // buy at price prices[i] and sell at price which is minimum till index (i-1)
        mn = min(mn, prices[i]);
    }
    return ans;
}