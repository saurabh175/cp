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
vvi g;
int ans;
int n, m;
struct DSU
{
    vi leader;
    vi size;
    DSU(int n)
    {
        leader.assign(n + 2, 0);
        size.assign(n + 2, 0);
        for (int i = 1; i <= n; i++)
        {
            leader[i] = i;
            size[i] = 1;
        }
    };
    int findleader(int i)
    {
        if (leader[i] == i)
            return i;
        return leader[i] = findleader(leader[i]);
    };
    void merge(int i, int j)
    {
        // cout << "insidemerge" << endl;
        i = findleader(i), j = findleader(j);
        if (i == j)
            return;
        int prvsize = size[i];
        leader[j] = i;
        size[i] += size[j];
        ans += (size[i] * (size[i] - 1)) / 2 - (prvsize * (prvsize - 1)) / 2 - (size[j] * (size[j] - 1)) / 2;
    };
};
void dfs(int u, int parent, int count)
{
    int numchild = 0;
    if (a[u] == 1)
        count++;
    else
        count = 0;
    if (count > m)
        return;
    for (auto v : g[u])
    {
        if (v != parent)
        {
            dfs(v, u, count);
            numchild++;
        }
    }
    if (numchild == 0)
    {
        if (count <= m)
        {
            ans++;
        }
    }
}
void solve()
{
    cin >> n >> m;
    g.resize(n + 1);
    a.resize(n + 1);
    fo(i, 1, n + 1)
    {
        cin >> a[i];
    }
    fo(i, 0, n - 1)
    {
        int x, y;
        cin >> x >> y;
        if (x != y)
        {
            g[x].pb(y);
            g[y].pb(x);
        }
    }
    dfs(1, -1, 0);
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
/* #include <bits/stdc++.h>
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
int ans;
int n, m;
bool dfs(int u)
{
    for (auto v : g[u])
    {
        if (a[v] == a[u])
            return false;
        if (!vis[v])
        {
            vis[v] = true;
            a[v] = (!a[u]);
            if (!dfs(v))
                return false;
        }
    }
    return true;
}
void solve()
{
    cin >> n >> m;
    g.resize(n + 1);
    a.resize(n + 1, 2);
    a[1] = 0;
    vi v2;
    fo(i, 0, m)
    {
        int x, y;
        cin >> x >> y;
        v2.pb(x);
        if (x != y)
        {
            g[x].pb(y);
            g[y].pb(x);
        }
    }
    if (dfs(1))
    {
        cout << "YES" << endl;
        for (auto x : v2)
        {
            if (a[x] == 0)
            {
                cout << 1;
            }
            else
                cout << 0;
        }
    }
    else
        cout << "NO" << endl;
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
/*