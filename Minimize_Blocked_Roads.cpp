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
vector<vp> g;
vi subtree;
int ans;
int n, k;
int dfs(int u, bool blocked)
{
    vis[u] = true;
    int nodes = 1;
    for (auto v : g[u])
    {
        if (!vis[v.ff])
        {

            int x = dfs(v.ff, blocked || v.ss);
            nodes += x;
            if (v.ss && !blocked)
            {
                subtree.pb(x);
            }
        }
    }
    return nodes;
}
void solve()
{
    cin >> n >> k;
    g.resize(n + 1);
    fo(i, 1, n + 1)
    {
        vis[i] = 0;
    }
    fo(i, 1, n)
    {
        int u, v, x;
        cin >> u >> v >> x;
        g[u].pb({v, x});
        g[v].pb({u, x});
    }
    dfs(1, 0);
    int infected = n;
    if (infected <= k)
    {
        cout << 0 << endl;
        subtree.clear();
        g.clear();
        return;
    }
    else
    {
        sort(all(subtree), greater<int>());
        fo(i, 0, subtree.sz)
        {
            infected -= subtree[i];
            if (infected <= k)
            {
                cout << i + 1 << endl;
                subtree.clear();
                g.clear();
                return;
            }
        }
    }
    cout << -1 << endl;
    subtree.clear();
    g.clear();
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
