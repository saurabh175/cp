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
struct DSU
{
    vi leader;
    vi size;
    DSU(int n)
    {
        leader.assign(n + 2, 0);

        for (int i = 1; i <= n; i++)
        {
            leader[i] = i;
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

        leader[j] = i;
    };
};
void solve()
{
    int n;
    cin >> n;
    vvi edge(n - 1, vi(2));
    fo(i, 0, n - 1)
    {
        int u, v;
        cin >> u >> v;
        edge[i][0] = u, edge[i][1] = v;
    }
    DSU ds(n);
    vp add, remove;
    fo(i, 0, n - 1)
    {
        if (ds.findleader((edge[i][0])) == ds.findleader(edge[i][1]))
        {
            // cout << edge[i][0] << " " << edge[i][1] << "remove" << endl;
            remove.pb({edge[i][0], edge[i][1]});
        }
        else
        {
            // cout << edge[i][0] << " " << edge[i][1] << "add" << endl;
            ds.merge(edge[i][0], edge[i][1]);
        }
    }
    fo(i, 1, n)
    {
        if (ds.findleader(i) != ds.findleader(i + 1))
        {
            // cout << edge[i][0] << " " << edge[i][1] << "addinside" << endl;
            ds.merge(i, i + 1);
            add.pb({i, i + 1});
        }
    }
    cout << max(add.sz, remove.sz) << endl;
    if (add.sz < remove.sz)
    {
        fo(i, 0, add.sz)
        {
            cout << remove[i].ff << " " << remove[i].ss << " " << add[i].ff << " " << add[i].ss << endl;
        }
        fo(i, add.sz, remove.sz)
        {
            cout << remove[i].ff << " " << remove[i].ss << " " << 0 << " " << 0 << endl;
        }
    }
    else
    {
        fo(i, 0, remove.sz)
        {
            cout << remove[i].ff << " " << remove[i].ss << " " << add[i].ff << " " << add[i].ss << " " << endl;
        }
        fo(i, remove.sz, add.sz)
        {
            cout << 0 << " " << 0 << " " << add[i].ff << " " << add[i].ss << endl;
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
