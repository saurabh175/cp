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
struct node
{
    int first, second, ind;
};
bool comp(pair<int, int> p1, pair<int, int> p2)
{
    return (p1.ff > p2.ff);
}
bool comp1(node p1, node p2)
{
    return (p1.ff < p2.ff);
}
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<node> v;
    vp v1;
    int x, y;
    fo(i, 0, m)
    {
        cin >> x >> y;
        v.pb({x, y, i + 1});
        v1.pb({y, x});
    }
    sort(all(v), comp1);
    sort(all(v1), comp);
    map m1;
    x = m - 2 * n;
    int i = 0;
    while (x--)
    {
        m1[v1[i++].ss] = 1;
    }
    int ans1 = 0;
    vi lans, rans;
    int count = 0;
    for (auto x : v)
    {
        if (m1[x.ff] != 1)
        {
            ans1 += x.ss;
            if (count < n)
            {
                lans.pb(x.ind);
                count++;
            }
            else
            {
                rans.pb(x.ind);
                count++;
            }
        }
    }
    cout << ans1 << endl;
    fo(i, 0, n)
    {
        cout << lans[i] << " " << rans[n - i - 1] << endl;
    }
    cout << endl;
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
