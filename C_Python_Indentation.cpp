#include <bits/stdc++.h>
using namespace std;
#define int long long
#define vi vector<int>
#define vc vector<char>
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
    vvi dp(n + 2, vi(n + 2));
    vc v(n + 1);
    fo(i, 1, n + 1) cin >> v[i];
    fo(l, 0, n + 2) dp[n][l] = 1;
    // dp[1][1];
    // int sum = 0;
    for (int i = n - 1; i >= 1; i--)
    {
        int sum = 0;
        for (int l = 0; l <= n; l++)
        {

            sum += dp[i + 1][l]; // sum stores dp[i + 1][l] + dp[i + 1][l - 1] + dp[i + 1][l - 2] + ... + dp[i + 1][0]
            sum %= mod;

            if (v[i] == 'f')
            {
                dp[i][l] = dp[i + 1][l + 1];
            }
            else
            {
                dp[i][l] = sum;
            }
        }
    }
    cout << dp[1][0] << endl;
}
int32_t main()
{
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
