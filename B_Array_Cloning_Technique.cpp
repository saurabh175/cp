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
    vi v(n);
    fo(i, 0, n)
    {
        cin >> v[i];
    }
    sort(all(v));

    int count = 1;
    int Max = 0;
    int ok = 0;
    int ans = 0;
    fo(i, 0, n - 1)
    {
        if (v[i] == v[i + 1])
        {
            count++;
            if (count >= Max)
            {
                Max = count;
            }
        }
        else
        {
            ok = 1;
            if (count >= Max)
            {
                Max = count;
            }
            count = 1;
        }
    }
    if (ok == 0)
    {
        cout << 0 << endl;
    }
    else
    {
        n -= Max;
        while (n >= Max)
        {
            ans += Max;
            n -= Max;
            Max *= 2;
            ans++;
        }
        if (n != 0)
        {
            cout << ans + n + 1 << endl;
        }
        else
        {
            cout << ans + n << endl;
        }
    }
}
int32_t main()
{
    int t = 1;
    cin >> t;
    fo(i, 1, t + 1)
    {
        solve();
    }
    return 0;
}
