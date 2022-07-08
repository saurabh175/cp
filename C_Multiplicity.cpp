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
void solve()
{
    int n;
    cin >> n;
    vi a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    vi dp(1e6 + 1);

    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {

        vi toUpdate;
        for (int j = 1; j <= sqrt(a[i]); j++)
        {
            if (a[i] % j == 0)
            {
                toUpdate.pb(j);
                if (a[i] / j != j)
                {
                    toUpdate.pb(a[i] / j);
                }
            }
        }

        sort(toUpdate.begin(), toUpdate.end());
        reverse(toUpdate.begin(), toUpdate.end());
        for (auto x : toUpdate)
        {
            cout << x << " ";
        }
        cout << endl;
        for (int j : toUpdate)
        {

            dp[j] += dp[j - 1];
            dp[j] %= mod;
        }
        cout << dp[1] << "hi " << i << endl;
        cout << dp[2] << " bi" << i << endl;
        cout << endl;
    }

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        cout << dp[i] << " ";
        ans = (ans + dp[i]) % mod;
    }
    cout << endl;
    cout << ans;
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
