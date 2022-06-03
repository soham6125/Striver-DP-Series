// https://leetcode.com/problems/largest-divisible-subset/

class Solution
{
public:
    vector<int> largestDivisibleSubset(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> lis(n, 0), ind(n, -1);
        int mx = 0, last = -1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (lis[j] + 1 > lis[i] and nums[i] % nums[j] == 0)
                {
                    lis[i] = lis[j] + 1;
                    mx = max(mx, lis[i]);
                    ind[i] = j;
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (lis[i] == mx)
            {
                last = i;
            }
        }
        vector<int> ans;
        while (last != -1)
        {
            ans.push_back(nums[last]);
            last = ind[last];
        }
        return ans;
    }
};