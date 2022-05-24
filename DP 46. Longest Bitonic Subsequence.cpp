int longestBitonicSequence(vector<int> &arr, int n)
{
    vector<int> lis(n, 0); // to store longest increasing subsequence from index 0 to index i
    vector<int> lds(n, 0); // to store longest decreasing subsequence from index i to index n-1
    for (int i = 0; i < n; i++)
    {
        lis[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j])
            {
                lis[i] = max(lis[i], lis[j] + 1);
            }
        }
    }
    for (int i = n - 1; i >= 0; i--)
    {
        lds[i] = 1;
        for (int j = n - 1; j > i; j--)
        {
            if (arr[j] < arr[i])
            {
                lds[i] = max(lds[i], lds[j] + 1);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
        ans = max(ans, lis[i] + lds[i] - 1); // -1 because arr[i] will be considered twice in ans
    return ans;
}
