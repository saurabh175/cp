#include <bits/stdc++.h>
using namespace std;
#define int long long
#define vi vector<int>
#define vs vector<string>
#define set set<int>
#define sets set<string>
#define vp vector<pair<int, int>>
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
    int start = 0, le = 0;
    vi ans;
    map<int, int> dp;
    int n, x;
    cin >> n;
    vi v(n);
    fo(i, 0, n) cin >> v[i];
    fo(i, 0, n)
    {
        x = v[i];

        if (dp[x] <= 1)
        {
            dp[x] = 1;
        }
        if (dp[x] < dp[x - 1] + 1)
        {
            dp[x] = dp[x - 1] + 1;
        }
        if (dp[x] > le)
        {
            le = dp[x];
            start = x - dp[x] + 1;
        }
    }
    fo(i, 0, n)
    {
        if (v[i] == start)
        {
            ans.pb(i + 1);
            start++;
        }
    }
    cout << ans.sz << endl;
    for (auto x : ans)
    {
        cout << x << " ";
    }
    cout << endl;
}
int32_t main()
{
    int t = 1;

    while (t--)
    {
        solve();
    }
    return 0;
}
