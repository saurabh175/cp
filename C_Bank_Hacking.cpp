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
#define inf 1e18
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
int n = 3e5 + 1;
vvi g(n);
vi v(n);
void solve()
{
    cin >> n;
    int res = -1e9;
    fo(i, 1, n + 1)
    {
        cin >> v[i];
        res = max(v[i], res);
    }
    int x = 0, y = 0;
    fo(i, 1, n + 1)
    {
        if (v[i] == res)
            x++;
        else if (v[i] == res - 1)
            y++;
    }
    fo(i, 1, n)
    {
        int x, y;
        cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }
    int ans = res + 2, a, b;
    fo(i, 1, n + 1)
    {
        a = x, b = y;
        if (v[i] == res)
        {
            x--;
        }
        else if (v[i] == res - 1)
            y--;
        for (auto j : g[i])
        {
            if (v[j] == res)
                x--, y++;
            else if (v[j] == res - 1)
                y--;
        }
        if (x == 0)
        {
            ans = min(ans, res + 1);
            if (y == 0)
            {
                ans = min(ans, res);
            }
        }
        x = a, y = b;
    }
    cout << ans << endl;
}
int32_t main()
{
    int t = 1;
    // cin >> t;
    fo(i, 1, t + 1)
    {
        solve();
    }
    return 0;
}
