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
int ans = 0;
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
bool comp1(vi &v1, vi &v2)
{
    return (v1[2] < v2[2]);
};
bool comp2(pair<int, int> &p1, pair<int, int> &p2)
{
    return (p1.ff < p2.ff);
}
void solve()
{
    int n, m;
    cin >> n >> m;
    vvi edge(n - 1, vi(3));
    vp q(m);
    fo(i, 0, n - 1)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edge[i][0] = u, edge[i][1] = v, edge[i][2] = w;
    }
    fo(i, 0, m)
    {
        int u;
        cin >> u;
        q[i].ff = u, q[i].ss = i;
    }

    sort(all(edge), comp1);
    sort(all(q), comp2);
    vi out(m);
    DSU ds(n);
    int pos = 0;
   
    for (auto x : q)
    {
        int qw = x.ff, qi = x.ss;
      //  cout << qw << " " << qi << endl;
        for (; pos < n - 1; pos++)
        {
            if (edge[pos][2] <= qw)
            {
             //   cout << "merge" << endl;
                ds.merge(edge[pos][0], edge[pos][1]);
            }
            else
                break;
        }
        out[qi] = ans;
    }
    for (auto x : out)
    {
        cout << x << " ";
    }
    cout << endl;
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
