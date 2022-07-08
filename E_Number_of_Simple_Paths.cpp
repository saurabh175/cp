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
vector<bool> vis;
vvi g;
int ans, n, m, ct;
bool ok = true;
set cnode;
int f;
bool dfs(int u, int parent)
{
    vis[u] = true;
    for (auto v : g[u])
    {
        if (vis[v] && v != parent)
        {
            cnode.insert(u);
            cnode.insert(v);
            f = v;
            return true;
        }
        else if (!vis[v])
        {
            if (dfs(v, u))
            {
                if (u != f)
                {
                    cnode.insert(u);
                }
                else
                {
                    return false;
                }
                return true;
            }
        }
    }
    return false;
};
vi sub(n + 1);
int dfs2(int u, int parent)
{
    sub[u] = 1;
    for (auto v : g[u])
    {
        if (cnode.find(v) == cnode.end() && v != parent)
            sub[u] += dfs2(v, u);
    }
    return sub[u];
}
void dfs1(int u)
{
    vis[u] = true;
    ct++;
    for (auto v : g[u])
    {
        if (!vis[v] && cnode.find(v) == cnode.end())
        {
            dfs1(v);
        }
    }
    vis[u] = 0;
};
void solve()
{
    ok = 1;
    dfs(1, 0);
    ans = 0;
    ans += n * (n - 1);
    fo(i, 1, n + 1) vis[i] = 0;
    for (auto u : cnode)
    {
        int snode = 1;
        ct = 0;
        // dfs1(u);
        dfs2(u, -1);
        // snode = ct;
        snode = sub[u];
        ans -= (snode * (snode - 1)) / 2;
    }
    cout << ans << endl;
}
int32_t main()
{
    int t = 1;
    cin >> t;
    fo(i, 1, t + 1)
    {

        cin >> n;
        g.resize(n + 1);
        vis.resize(n + 1, 0);
        fo(i, 0, n)
        {
            int x, y;
            cin >> x >> y;
            g[x].pb(y);
            g[y].pb(x);
        }
        solve();
        g.clear();
        vis.clear();
        cnode.clear();
        ct = 1;
    }
    return 0;
}
