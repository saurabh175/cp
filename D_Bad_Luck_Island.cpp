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
#define total(c) c.begin(), c.end()
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
vector<vector<vector<long double>>> dp1(101, vector<vector<long double>>(101, vector<long double>(101, -1)));
vector<vector<vector<long double>>> dp2(101, vector<vector<long double>>(101, vector<long double>(101, -1)));
vector<vector<vector<long double>>> dp3(101, vector<vector<long double>>(101, vector<long double>(101, -1)));

long double solve1(int r, int s, int p)
{
    if (dp1[r][s][p] != -1)
        return dp1[r][s][p];
    if (r == 0)
        return dp1[r][s][p] = 0;
    if (r > 0 && s == 0 && p == 0)
        return dp1[r][s][p] = 1;
   long double total = 0;
    if (r > 0 && s > 0)
        total += r * s;
    if (s > 0 && p > 0)
        total += s * p;
    if (p > 0 && r > 0)
        total += r * p;
    dp1[r][s][p] = 0;
    if (r > 0 && s > 0)
    {
        dp1[r][s][p] += (r * s / total) * solve1(r, s - 1, p);
    }
    if (r > 0 && p > 0)
    {
        dp1[r][s][p] += (r * p / total) * solve1(r - 1, s, p);
    }
    if (s > 0 && p > 0)
    {
        dp1[r][s][p] += (p * s / total) * solve1(r, s, p - 1);
    }
    return dp1[r][s][p];
}
 long double solve2(int r, int s, int p)
{
    if (dp2[r][s][p] != -1)
        return dp2[r][s][p];
    if (s == 0)
        return dp2[r][s][p] = 0;
    if (s > 0 && r == 0 && p == 0)
        return dp2[r][s][p] = 1;
    long double total = 0;
    if (r > 0 && s > 0)
        total += r * s;
    if (s > 0 && p > 0)
        total += s * p;
    if (p > 0 && r > 0)
        total += r * p;
    dp2[r][s][p] = 0;
    if (r > 0 && s > 0)
    {
        dp2[r][s][p] += (r * s / total) * solve2(r, s - 1, p);
    }
    if (r > 0 && p > 0)
    {
        dp2[r][s][p] += (r * p / total) * solve2(r - 1, s, p);
    }
    if (s > 0 && p > 0)
    {
        dp2[r][s][p] += (p * s / total) * solve2(r, s, p - 1);
    }
    return dp2[r][s][p];
}
 long double solve3(int r, int s, int p)
{
    if (dp3[r][s][p] != -1)
        return dp3[r][s][p];
    if (p == 0)
        return dp3[r][s][p] = 0;
    if (p > 0 && s == 0 && r == 0)
        return dp3[r][s][p] = 1;
    long double total = 0;
    if (r > 0 && s > 0)
        total += r * s;
    if (s > 0 && p > 0)
        total += s * p;
    if (p > 0 && r > 0)
        total += r * p;
    dp3[r][s][p] = 0;
    if (r > 0 && s > 0)
    {
        dp3[r][s][p] += (r * s / total) * solve3(r, s - 1, p);
    }
    if (r > 0 && p > 0)
    {
        dp3[r][s][p] += (r * p / total) * solve3(r - 1, s, p);
    }
    if (s > 0 && p > 0)
    {
        dp3[r][s][p] += (p * s / total) * solve3(r, s, p - 1);
    }
    return dp3[r][s][p];
}
void solve()
{
    int r, s, p;
    cin >> r >> s >> p;
    cout << setprecision(12) << solve1(r, s, p) << " " << solve2(r, s, p) << " " << solve3(r, s, p) << endl;
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
