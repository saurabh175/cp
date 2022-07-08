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
vi a;
vector<bool> vis(1e6);
vvi g;
vi power2(10e6);
int n, m;
int c0, c1;
bool dfs(int u)
{
    vis[u] = 1;
    for (auto v : g[u])
    {
        if (a[v] == a[u])
            return false;
        if (!vis[v])
        {
            a[v] = (!a[u]);
            if (a[v])
                c1++;
            else
                c0++;
            if (!dfs(v))
                return false;
        }
    }
    return true;
}
void solve()
{
    int ans = 1;

    fo(i, 1, n + 1)
    {
        c0 = 0;
        c1 = 1;
        a[i] = 1;
        if (!vis[i])
        {

            if (!dfs(i))
            {
                cout << 0 << endl;
                return;
            }
            ans = (ans * ((power2[c1] + power2[c0]) % 998244353)) % 998244353;
        }
    }
    cout << ans << endl;
}

int32_t main()
{
    int t = 1;
    cin >> t;

    fo(i, 1, t + 1)
    {
        cin >> n >> m;
        power2[0] = 1;
        fo(i, 1, n + 1)
        {
            vis[i] = 0;
            power2[i] = (power2[i - 1] * 2) % 998244353;
        }
        g.resize(n + 1);
        a.resize(n + 1, -1);
        //
        fo(i, 0, m)
        {
            int x, y;
            cin >> x >> y;
            if (x != y)
            {
                g[x].pb(y);
                g[y].pb(x);
            }
        }
        solve();
        g.clear();
        a.clear();
    }
    return 0;
}
