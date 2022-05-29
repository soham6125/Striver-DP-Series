// https://leetcode.com/problems/longest-increasing-subsequence/

// Solution in O(n*logn) using binary search
int lis(vector<int> &a)
{
    int n = a.size();
    vector<int> dp;
    for (int &i : a)
    {
        if (dp.size() == 0)
        {
            dp.push_back(i);
            continue;
        }
        int x = upper_bound(dp.begin(), dp.end(), i) - dp.begin();
        if (x == dp.size())
            dp.push_back(i);
        else
        {
            dp[x] = i;
        }
    }
    return dp.size();
}