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
void solve()
{
    int n, x, curr = 0;
    cin >> n >> x;
    vi v(n), total(n + 1, 0);
    fo(i, 0, n) cin >> v[i];
    vi currmax(n + 1, INT_MIN);
    currmax[0] = 0;
    int overmax = 0, overk = 0;
    fo(i, 0, n)
    {
        total[i + 1] = total[i] + v[i];
    }
    fo(l, 1, n + 1)
    {
        fo(i, l, n + 1)
        {
            currmax[l] = max(currmax[l], total[i] - total[i - l]);
            if (currmax[l] > overmax)
            {
                overmax = currmax[l];
                overk = l;
            }
        }
    }
    fo(i, 0, n + 1)
    {
        if (i > overk)
        {
            int maxvalue1 = overmax + x * overk, maxvalue = INT_MIN;
            fo(k, overk + 1, n + 1)
            {
                if (k < i)
                    maxvalue = max(maxvalue, currmax[k] + k * x);
                else
                    maxvalue = max(maxvalue, currmax[k] + i * x);
            }
            cout << max(maxvalue1, maxvalue) << " ";
        }
        else
        {
            cout << overmax + i * x << " ";
        }
    }
    cout << endl;
}
int32_t main()
{
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
