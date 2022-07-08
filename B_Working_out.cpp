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
    vvi v(n + 2, vi(m + 2));
    fo(i, 1, n + 1)
    {
        fo(j, 1, m + 1) cin >> v[i][j];
    }
    vvi dp1(n + 2, vi(m + 2)); // 1,1 to i,j
    vvi dp2(n + 2, vi(m + 2)); // n,1 to 1,m
    vvi dp3(n + 2, vi(m + 2)); // i,j to n,n
    vvi dp4(n + 2, vi(m + 2)); // i,j to 1,m
    fo(i, 1, n + 1)
    {
        fo(j, 1, m + 1)
        {
            dp1[i][j] = v[i][j] + max(dp1[i][j - 1], dp1[i - 1][j]);
        }
    }
    rfo(i, 1, n + 1)
    {
        fo(j, 1, m + 1)
        {
            dp2[i][j] = v[i][j] + max(dp2[i + 1][j], dp2[i][j - 1]);
        }
    }
    rfo(i, 1, n + 1)
    {
        rfo(j, 1, m + 1)
        {
            dp3[i][j] = v[i][j] + max(dp3[i][j + 1], dp3[i + 1][j]);
        }
    }
    fo(i, 1, n + 1)
    {
        rfo(j, 1, m + 1)
        {
            dp4[i][j] = v[i][j] + max(dp4[i - 1][j], dp4[i][j + 1]);
        }
    }
    int ans = 0;
    fo(i, 2, n)
    {
        fo(j, 2, m)
        {
            int case1 = dp1[i][j - 1] + dp3[i][j + 1] + dp2[i + 1][j] + dp4[i - 1][j];
            int case2 = dp1[i - 1][j] + dp3[i + 1][j] + dp2[i][j - 1] + dp4[i][j + 1];
            ans = max(ans, max(case1, case2));
        }
    }
    cout << ans << endl;
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
