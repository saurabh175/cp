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
    int n, x, y;
    cin >> n >> x >> y;
    int s = (n * (n + 1)) / 2;
    int sum1 = (s * x) / (x + y);
    int sum2 = (s * y) / (x + y);

    if (sum1 + sum2 == s)
    {
        cout << "POSSIBLE" << endl;
        vi arr(n);
        fo(i, 0, n)
        {
            arr[i] = i + 1;
        }
        vi ans;
        rfo(i, 0, n)
        {
            if (sum1 > arr[i])
            {
                ans.pb(arr[i]);
                sum1 -= arr[i];
            }
            else if (sum1 <= arr[i] && sum1 > 0)
            {
                ans.pb(sum1);
                break;
            }
            else
                break;
        }
        cout << ans.sz << endl;
        for (auto x : ans)
        {
            cout << x << " ";
        }
        cout << endl;
        // printAllSubsets(arr, n, sum1);
        // subset_sum(s, t, n, 0, 0, 0, sum1);
    }
    else
    {
        cout << "IMPOSSIBLE" << endl;
    }
}
int32_t main()
{
    fast;
    int t = 1;
    cin >> t;
    fo(i, 1, t + 1)
    {
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}
