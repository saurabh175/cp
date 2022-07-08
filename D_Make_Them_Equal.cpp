#include <bits/stdc++.h>
using namespace std;
#define int long long
#define vi vector<int>
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
int N = 1001;
vector<int> dp(N, N);
void minimumoperation()
{

    dp[1] = 0;
    for (int i = 1; i < N; ++i)
    {
        for (int x = 1; x <= i; ++x)
        {
            int j = i + i / x;
            if (j < N)
                dp[j] = min(dp[j], dp[i] + 1);
        }
    }
}
void solve()
{
    int n, k;
    cin >> n >> k;
    vi b(n), c(n);
    fo(i, 0, n) cin >> b[i];
    fo(i, 0, n) cin >> c[i];
    int count = 0;
    vector<pair<double, int>> ans;
    fo(i, 0, n)
    {
        int x = dp[b[i]];
        if (b[i] == 1)
        {
            count += c[i];
        }
        else
        {
            //  cout << c[i] / (x * 1.0) << " " << i << endl;
            ans.pb({c[i] / (x * 1.0), i});
        }
    }
    sort(all(ans), greater<pair<double, int>>());
    int sum = 0;
    for (int x : b)
        sum += dp[x];
    k = min(k, sum);
    for (auto x : ans)
    {
        if (dp[b[x.ss]] <= k && k != 0)
        {
            count += c[x.ss];
            k -= dp[b[x.ss]];
            // cout << k << " " << count << endl;
        }
    }
    cout << count << endl;
}
int32_t main()
{
    int t = 1;
    cin >> t;
    minimumoperation();
    while (t--)
    {
        solve();
    }
    return 0;
}
