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
bool comp(pair<int, int> p1, pair<int, int> p2)
{
    return (p1.ff > p2.ff);
}
void solve()
{
    int n, d;
    cin >> n >> d;
    vp v(n);
    int sum = 0;
    fo(i, 0, n)
    {
        cin >> v[i].ff >> v[i].ss;
        sum += v[i].ss;
    }
    if (d == 0)
    {
        cout << sum << endl;
        return;
    }
    sort(all(v), comp);
    int cur = v[0].ss, ans = v[0].ss;
    int j = 0, i = 0;
    vi prf(n + 1);
    prf[0] = 0;
    fo(i, 1, n + 1)
    {
        prf[i] = prf[i - 1] + v[i-1].ss;
    }
    while (i < n && j < n)
    {
        if (v[i].ff - v[j].ff < d)
        {
            ans = max(ans, prf[j + 1] - prf[i]);
            j++;
        }
        else
        {
            i++;
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
