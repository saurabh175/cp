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
    int n, m;
    cin >> n >> m;
    vi v(n + 1);
    fo(i, 1, n + 1)
    {
        cin >> v[i];
        v[i] %= m;
    }
    if (n >= m)
        cout << "YES" << endl;
    else
    {
        vvi dp(n + 1, vi(m + 1));
        fo(i, 1, n + 1) dp[i][v[i]] = 1;
        fo(i, 2, n + 1)
        {
            fo(j, 0, m)
            {
                if (dp[i][j])
                    continue;
                if (dp[i - 1][j])
                {
                    dp[i][j] = dp[i - 1][j];
                    continue;
                }
                dp[i][j] = dp[i - 1][(j - v[i] + m) % m];
            }
        }
        if (dp[n][0])
            cout << "YES" << endl;
        else cout << "NO" << endl;
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
