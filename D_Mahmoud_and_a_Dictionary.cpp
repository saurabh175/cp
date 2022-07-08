#include <bits/stdc++.h>
using namespace std;
#define int long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define vs vector<string>
#define set set<int>
#define sets set<string>
#define vp vector<pair<int, int>>
#define mapi map<int, int>
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
struct DSU
{
    vi p;
    int n;
    DSU(int _n)
    {
        n = _n;
        p.assign(2 * n, 0);
        fo(i, 0, 2 * n)
        {
            p[i] = i;
        }
    }
    int find(int i)
    {
        if (p[i] == i)
            return i;
        return p[i] = find(p[i]);
    }
    bool arefriends(int u, int v)
    {
        return find(u) == find(v);
    }
    bool areenemies(int u, int v)
    {
        int fu = find(u), fv = find(v), eu = find(u + n), ev = find(v + n);
        if (fu == ev || fv == eu)
        {
            return true;
        }
        else
            return false;
    }
    void mergefriend(int u, int v)
    {
        int fu = find(u), fv = find(v), eu = find(u + n), ev = find(v + n);
        p[fv] = fu;
        p[ev] = eu;
    }
    void mergeenemy(int u, int v)
    {
        int fu = find(u), fv = find(v), eu = find(u + n), ev = find(v + n);
        p[fu] = ev;
        p[fv] = eu;
    }
};
void solve()
{
    int n, m, q;
    cin >> n >> m >> q;
    map<string, int> pos;
    DSU dis(n);
    fo(i, 0, n)
    {
        string s;
        cin >> s;
        pos[s] = i;
    }
    fo(i, 0, m)
    {
        int t;
        string s1, s2;
        cin >> t >> s1 >> s2;
        if (t == 1)
        {
            if (!dis.areenemies(pos[s1], pos[s2]))
            {
                cout << "YES" << endl;
                dis.mergefriend(pos[s1], pos[s2]);
            }
            else
            {
                cout << "NO" << endl;
            }
        }
        else
        {
            if (!dis.arefriends(pos[s1], pos[s2]))
            {
                cout << "YES" << endl;
                dis.mergeenemy(pos[s1], pos[s2]);
            }
            else
            {
                cout << "NO" << endl;
            }
        }
    }
    fo(i, 0, q)
    {
        string s1, s2;
        cin >> s1 >> s2;
        if (dis.arefriends(pos[s1], pos[s2]))
        {
            cout << 1 << endl;
        }
        else if (dis.areenemies(pos[s1], pos[s2]))
        {
            cout << 2 << endl;
        }
        else
            cout << 3 << endl;
    }
}
int32_t main()
{
    int t = 1;
    //  cin >> t;
    fo(i, 1, t + 1)
    {
        solve();
    }
    return 0;
}
