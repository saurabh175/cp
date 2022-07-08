#include <bits/stdc++.h>
using namespace std;
#define int long long
#define vi vector<int>
#define vc vector<char>
#define vvi vector<vector<int>>
#define vvc vector<vector<char>>
#define vvs vector<vector<string>>
#define vs vector<string>
#define seti set<int>
#define setc set<char>
#define sets set<string>
#define vp vector<pair<int, int>>
#define mapi map<int, int>
#define mapc map<char, int>
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
vector<bool> vis(1e6);
vvi g;
int n, m;
int i = 0;
map<pair<int, int>, int> ans;
vp edge;
set<pair<int, int>> s;
void dfs(int u)
{
    vis[u] = 1;
    for (auto v : g[u])
    {
        if (!vis[v])
        {
            dfs(v);
            if (i % 2 == 0)
            {
                pair<int, int> pa;
                pa = {u, v};
                if (s.find(pa) != s.end())
                {
                    ans[pa] = 2;
                }
                else
                {
                    pa = {v, u};
                    ans[pa] = 2;
                }
            }
            else
            {
                pair<int, int> pa;
                pa = {u, v};
                if (s.find(pa) != s.end())
                {
                    ans[pa] = 3;
                }
                else
                {
                    pa = {v, u};
                    ans[pa] = 3;
                }
            }
            i++;
        }
    }
}
void solve()
{
    cin >> n;
    i = 0;
    g.resize(n + 1);
    // ans.resize(n + 1);
    fo(i, 1, n + 1)
    {
        vis[i] = 0;
    }
    fo(i, 1, n)
    {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
        edge.pb({u, v});
        s.insert({u, v});
    }
    int leaf;
    fo(i, 1, n + 1)
    {
        if (g[i].sz >= 3)
        {
            cout << -1 << endl;
            ans.clear();
            g.clear();
            edge.clear();
            vis.clear();
            s.clear();
            i = 0;
            return;
        }
        else if (g[i].sz == 1)
            leaf = i;
    }
    i = 0;
    dfs(leaf);
    for (auto v : edge)
    {
        cout << ans[v] << " ";
    }
    cout << endl;
    s.clear();
    g.clear();
    edge.clear();
    vis.clear();
    ans.clear();
}
int32_t main()
{
    int t = 1;
    cin >> t;
    fo(i, 1, t + 1)
    {
        solve();
    }
    return 0;
}
