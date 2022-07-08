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
int n, m, ans = 2;
int c0, c1;
void dfs(int u)
{
    vis[u] = 1;
    for (auto v : g[u])
    {
        if (a[v] == a[u])
        {
            ans = 3;
            a[v] = 3;
            continue;
        }

        if (!vis[v])
        {

            if (a[u] == 1)
            {
              
                a[v] = 2;
            }
            else if (a[u] == 2)
            {
               
                a[v] = 1;
            }
            else
                a[v] = 1;
            dfs(v);
        }
    }
}
void solve()
{
    ans = 2;
    fo(i, 1, n + 1)
    {

        if (!vis[i])
        {
            a[i] = 1;
            dfs(i);
        }
    }
    cout << ans << endl;
    fo(i, 1, n + 1)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

int32_t main()
{
    int t = 1;
    cin >> t;

    fo(i, 1, t + 1)
    {
        cin >> n;

        vi v(n + 1);
        fo(i, 1, n + 1)
        {
            cin >> v[i];
            vis[i] = 0;
        }

        g.resize(n + 1);
        a.resize(n + 1, -1);
        //
        int count = 1;
        fo(i, 1, n)
        {
            if (v[i] != v[i + 1])
            {
                g[i].pb(i + 1);
                g[i + 1].pb(i);
                count = 0;
            }
            else
                count++;
        }
        if (v[1] != v[n])
        {
            g[1].pb(n);
            g[n].pb(1);
        }

        if (count == n)
        {
            cout << 1 << endl;
            fo(i, 1, n + 1)
            {
                cout << 1 << " ";
            }
            cout << endl;
            g.clear();
            a.clear();
            continue;
        }
        solve();
        g.clear();
        a.clear();
    }
    return 0;
}
