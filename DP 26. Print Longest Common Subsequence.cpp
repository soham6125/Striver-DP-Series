#pragma GCC optimize("O3,unroll-loops")

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace chrono;
using namespace __gnu_pbds;

#define ll long long int
#define loop(a, b, i) for (long long int i = a; i < b; i++)
#define loopr(a, b, i) for (long long int i = a; i >= b; i--)
#define cn continue;
#define pb push_back
#define db double
#define mp make_pair
#define sz(x) (ll)((x).size())
#define endl "\n"
#define lb lower_bound
#define ub upper_bound
#define f first
#define se second
#define vll vector<ll>
#define pll pair<ll, ll>
#define vpll vector<pair<ll, ll>>
#define all(x) x.begin(), x.end()
#define print(a, n)            \
    for (ll i = 0; i < n; i++) \
        cout << a[i] << " ";   \
    cout << endl;
#define pi 3.14159265358979323846
#define quick                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
typedef tree<pair<ll, ll>, null_type, less<pair<ll, ll>>, rb_tree_tag, tree_order_statistics_node_update> pbds;

const ll inf = 1e18;
const ll mod = 1e9 + 7;
const ll MAX = 8000000000000000064LL;
const ll MIN = -8000000000000000064LL;
ll add(ll x, ll y)
{
    ll res = x + y;
    return (res >= mod ? res - mod : res);
}
ll mul(ll x, ll y)
{
    ll res = x * y;
    return (res >= mod ? res % mod : res);
}
ll sub(ll x, ll y)
{
    ll res = x - y;
    return (res < 0 ? res + mod : res);
}
ll power(ll x, ll y)
{
    ll res = 1;
    x %= mod;
    while (y)
    {
        if (y & 1)
            res = mul(res, x);
        y >>= 1;
        x = mul(x, x);
    }
    return res;
}
ll mod_inv(ll x) { return power(x, mod - 2); }
ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
ll lcm(ll x, ll y)
{
    ll res = x / gcd(x, y);
    return (res * y);
}
// ll nCr(ll n,ll r){ll ans=fact[n]; ans*=mod_inv(fact[n-r]);ans%=mod; ans*=mod_inv(fact[r]);ans%=mod; return ans;}

const ll dx[] = {-1, 1, 0, 0, 1, 1, -1, -1};
const ll dy[] = {0, 0, 1, -1, -1, 1, -1, 1};

signed main()
{
    quick;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int tc = 1;
    // cin >> tc;
    loop(0, tc, Q)
    {
        // cout << "Case #" << Q+1 << ": ";
        string s1, s2;
        cin >> s1 >> s2;
        int m = s1.length(), n = s2.length();
        int L[m + 1][n + 1];
        for (int i = 0; i <= m; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                if (i == 0 or j == 0)
                    L[i][j] = 0;
                else if (s1[i - 1] == s2[j - 1])
                    L[i][j] = L[i - 1][j - 1] + 1;
                else
                    L[i][j] = max(L[i - 1][j], L[i][j - 1]);
            }
        }
        int index = L[m][n];
        char lcs[index + 1];
        lcs[index] = '\0';
        int i = m, j = n;
        while (i > 0 and j > 0)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                lcs[index - 1] = s1[i - 1];
                i--;
                j--;
                index--;
            }
            else if (L[i - 1][j] > L[i][j - 1])
                i--;
            else
                j--;
        }
        cout << lcs;
    }

    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
