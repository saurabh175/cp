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
/*vector<bool> vis(1e6);
vvi g;
int ans,n,m;
bool ok = true;
bool dfs(int u)
{
vis[u] = true;
  for (auto v : g[u])
{
if (!vis[v])
{
if(!dfs(v))return false;
}
}
return true;
};*/
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<set> g(n + 1);
    fo(i, 0, m)
    {
        int u, v;
        cin >> u >> v;
        g[u].insert(v);
        g[v].insert(u);
    }
    int ans = 0;
    vi is(n+1);
    fo(i, 1, n + 1)
    {
        if (g[i].lower_bound(i) == g[i].end())
            ans++, is[i] = 1;
    }
    int q;
    cin >> q;
    fo(i, 0, q)
    {
        int type;
        cin >> type;
        if (type == 3)
        {
            cout << ans << endl;
        }
        else
        {
            if (type == 1)
            {
                int u, v;
                cin >> u >> v;
                if (is[u])
                    ans--;
                if (is[v])
                    ans--;
                g[u].insert(v);
                g[v].insert(u);
                if (g[u].lower_bound(u) != g[u].end())
                    is[u] = 0;
                else
                    is[u] = 1;
                if (g[v].lower_bound(v) != g[v].end())
                    is[v] = 0;
                else
                    is[v] = 1;
                if (is[u])
                    ans++;
                if (is[v])
                    ans++;
            }
            else
            {
                int u, v;
                cin >> u >> v;
                if (is[u])
                    ans--;
                if (is[v])
                    ans--;
                g[u].erase(v);
                g[v].erase(u);
                if (g[u].lower_bound(u) != g[u].end())
                    is[u] = 0;
                else
                    is[u] = 1;
                if (g[v].lower_bound(v) != g[v].end())
                    is[v] = 0;
                else
                    is[v] = 1;
                if (is[u])
                    ans++;
                if (is[v])
                    ans++;
            }
        }
    }
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
