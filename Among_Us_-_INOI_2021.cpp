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
int ans = 0, n = 5e5 + 1, m;
vector<vector<vector<int>>> g(n);
bool ok = false;
vi col(n + 1);
int numcolor1, numcolor2;
void dfs(int u)
{
    if (col[u] == 1)
        numcolor1++;
    else
        numcolor2++;
    for (auto v : g[u])
    {
        int val = v[0];
        int type = v[1];
        if (col[val] != -1)
        {
            if (type == 1 && col[u] == col[val])
                ok = true;
            else if (type == 2 && col[u] != col[val])
                ok = true;
        }
        else
        {
            if (type == 1)
            {
                col[val] = 3 - col[u];
                dfs(val);
            }
            else
            {
                col[val] = col[u];
                dfs(val);
            }
        }
    }
};
void solve()
{
    cin >> n >> m;
    g.resize(n + 1);
    ok = false;
    numcolor1 = 0, numcolor2 = 0;
    ans = 0;
    fo(i, 0, m)
    {
        int type, u, v;
        cin >> type >> u >> v;
        g[u].pb({v, type});
        g[v].pb({u, type});
    }
    fo(i, 1, n + 1)
    {
        col[i] = -1;
    }
    fo(i, 1, n + 1)
    {
        numcolor1 = 0, numcolor2 = 0;
        if (col[i] == -1)
        {
            col[i] = 1;
            dfs(i);
        }
        ans += max(numcolor1, numcolor2);
    }
    if (ok)
        cout << -1 << endl;
    else
        cout << ans << endl;
}
int32_t main()
{
    int t = 1;
    cin >> t;
    fo(i, 1, t + 1)
    {

        solve();
        g.clear();
        col.clear();
    }
    return 0;
}
