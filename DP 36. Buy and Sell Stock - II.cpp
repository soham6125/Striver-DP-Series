// https://www.codingninjas.com/codestudio/problems/selling-stock_630282?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=1

long getMaximumProfit(long *values, int n)
{
    long ans = 0;
    for (int i = 1; i < n; i++)
    {
        if (values[i] > values[i - 1])
        {
            ans += (values[i] - values[i - 1]);
        }
    }
    return ans;
}