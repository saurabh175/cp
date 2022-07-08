#include <bits/stdc++.h>
using namespace std;
//#define int long long
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
int power(int x, int y, int m)
{
    int temp;
    if (y == 0)
        return 1;
    temp = (power(x, y / 2, m) % m);
    if (y % 2 == 0)
        return (temp * temp) % m;
    else
        return (((x * temp) % mod) * (temp % mod)) % m;
};
vector<bool> vis(1e6);
vvi g;
int ans;
int n, m;
void dfs(int u)
{
    vis[u] = true;
    for (auto v : g[u])
    {
        if (!vis[v])
        {
            dfs(v);
        }
    }
}
void solve()
{
    int n;
    cin >> n;
    vi a(n), b(n);
    fo(i, 0, n)
    {
        cin >> a[i];
    }
    fo(i, 0, n)
    {
        cin >> b[i];
    }
    bool ok = 0;
    vp v2;
    vp ans;
    vi temp1, temp2;
    temp1 = a, temp2 = b;
    sort(all(temp1));
    sort(all(temp2));
    fo(i, 0, n - 1)
    {
        fo(j, i + 1, n)
        {
            if (a[i] > a[j])
            {
                swap(a[i], a[j]);
                swap(b[i], b[j]);
                ans.pb({i + 1, j + 1});
            }
            else if (a[i] == a[j] && b[i] > b[j])
            {
                swap(a[i], a[j]);
                swap(b[i], b[j]);
                ans.pb({i + 1, j + 1});
            }
        }
    }
    if (temp1 == a && temp2 == b)
    {

        cout << ans.sz << endl;
        for (auto x : ans)
        {
            cout << x.ff << " " << x.ss << endl;
        }
    }
    else
    {
        cout << -1 << endl;
        return;
    }
}
int32_t main()
{
    fast;
    int t = 1;
    cin >> t;
    fo(i, 1, t + 1)
    {
        solve();
    }
    return 0;
}
