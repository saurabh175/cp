#include <bits/stdc++.h>
using namespace std;
#define int long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define vs vector<string>
#define set set<int>
#define sets set<string>
#define vp vector<pair<int, int>>
#define map map<int, int>
#define umap unordered_map<int>
#define pi (3.141592653589)
#define mod 1000000007
#define float double
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define sz size()
#define len length()
#define all(c) c.begin(), c.end()
#define min3(a, b, c) min(c, min(a, b))
#define min4(a, b, c, d) min(d, min(c, min(a, b)))
#define max3(a, b, c) max(c, max(a, b))
#define max4(a, b, c, d) max(d, max(c, max(a, b)))
#define rfo(i, j, n) for (int i = n - 1; i >= j; i--)
#define fo(i, j, n) for (int i = j; i < n; i++)
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

bool isPrime(int n)
{
    if (n == 1)
        return false;
    if (n == 2)
        return true;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

int GCD(int a, int b)
{
    while (b)
    {
        a %= b;
        swap(a, b);
    }
    return a;
}
int LCM(int a, int b)
{
    return (a * b) / GCD(a, b);
}

void solve()
{
    int n, h, l, r;
    cin >> n >> h >> l >> r;
    vi v(n + 2);
    vvi dp(n + 2, vi(h + 1));
    fo(i, 1, n + 2) cin >> v[i];
    fo(i, 0, h + 1) dp[n + 1][i] = 0;
    rfo(i, 1, n + 1)
    {
        fo(t, 0, h + 1)
        {
            // option 1:
            // dp[i][t]=dp[i+1][t1]+1;
            // t1=t+a[i]

            int t1 = (t + v[i]) % h;

            int cnt1 = (l <= t1 && t1 <= r) ? 1 : 0;
            dp[i][t] = dp[i + 1][t1] + cnt1;
            // option 2:
            int t2 = (t + v[i] - 1) % h;

            int cnt2 = (l <= t2 && t2 <= r) ? 1 : 0;
            dp[i][t] = max(dp[i][t], dp[i + 1][t2] + cnt2);
        }
    }
    cout << dp[1][0] << endl;
}
int32_t main()
{
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
