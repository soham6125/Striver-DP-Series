// https://leetcode.com/problems/longest-string-chain/

class Solution
{
public:
    static bool cmp(string &s, string &t)
    {
        return s.length() < t.length();
    }

    bool check(string &s, string &t)
    {
        int n = s.size(), m = t.size();
        if (n != m + 1)
            return 0;
        int i = 0, j = 0;
        while (i < n)
        {
            if (s[i] == t[j])
            {
                i++;
                j++;
            }
            else
                i++;
        }
        return (i == n and j == m);
    }

    int longestStrChain(vector<string> &words)
    {
        sort(words.begin(), words.end(), cmp);
        int n = words.size();
        int ans = 1;
        vector<int> dp(n, 1);
        for (int i = 0; i < n; i++)
        {
            dp[i] = 1;
            for (int j = 0; j < i; j++)
            {
                if (check(words[i], words[j]))
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};