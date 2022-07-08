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
void solve()
{
    int n;
    cin >> n;
    vi a(n), b(n);
    map<int, int> m;
    fo(i, 0, n)
    {
        cin >> a[i];
    }
    fo(i, 0, n)
    {
        cin >> b[i];
    }
    int ans = 0;
    fo(i, 0, n)
    {
        m[a[i] ^ b[i]]++;
    }
    for (auto x : m)
    {
        ans += (x.ss * (x.ss - 1)) / 2;
    }

    cout << ans << endl;
}
int change(int amount, vector<int> &coins)
{
    int l = coins.size();
    vector<vector<int>> dp(amount + 1, vector<int>(l + 1, 0));
    dp[amount][l - 1] = 1;
    int last = l - 1;
    for (int i = amount; i >= 0; i--)
    {
        for (int j = last; j < l; j++)
        {
            if (i + coins[j] <= amount)
                dp[i][last] += dp[i + coins[j]][j];
        }
        last--;
    }
    int ans = 0;
    for (int i = 0; i < l; i++)
    {
        ans += dp[0][i];
    }
    return ans;
}
int32_t main()
{
    int t = 1;
    cin >> t;
    fo(i, 1, t + 1)
    {
        int amount;
        cin >> amount;
        int n;
        cin >> n;
        vi v(n);
        fo(i, 0, n)
        {
            cin >> v[i];
        }
        cout << change(amount, v) << endl;
        
        // solve();
    }
    return 0;
}
