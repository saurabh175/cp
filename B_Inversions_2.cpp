#include <bits/stdc++.h>
using namespace std;
#define int long long
#define vi vector<int>
#define vc vector<char>
#define vvi vector<vector<int>>
#define vvc vector<vector<char>>
#define vvs vector<vector<string>>
#define vs vector<string>
#define seti set<int>
#define setc set<char>
#define sets set<string>
#define vp vector<pair<int, int>>
#define mapi map<int, int>
#define mapc map<char, int>
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

vector<bool> vis(1e6);
vvi g;
int ans;
int n, m;
vi num;

vector<long long> tre;

int f(int si, int sl, int sr, int ql, int qr, int v)
{
    if (ql <= sl && sr <= qr)
    {
        if (v != -1)
        {
            tre[si] = v;
        }
        return tre[si];
    }
    if (sr < ql || sl > qr)
    {
        return 0;
    }
    int mid = sl + (sr - sl) / 2;
    long long sum = f(2 * si, sl, mid, ql, qr, v) + f(2 * si + 1, mid + 1, sr, ql, qr, v);
    tre[si] = tre[2 * si] + tre[2 * si + 1];
    return sum;
}
void search_kth_one(int si, int sl, int sr, int k)
{
    if (k == 0 && sl == sr)
    {
        if (tre[si] == 1)
        {
            ans = sl + 1;
            return;
        }
    }
    int mid = sl + (sr - sl) / 2;
    if (tre[2 * si + 1] > k)
    {
        search_kth_one(2 * si + 1, mid + 1, sr, k);
    }
    else
        search_kth_one(2 * si, sl, mid, k - tre[2 * si + 1]);
}
void solve()
{
    int q;
    cin >> n;
    int temp = n;
    vi num(n, 1);
    while (__builtin_popcount(n) != 1)
    {
        n++;
        num.pb(0);
    }
    tre.resize(2 * n);
    for (int i = 0; i < n; i++)
    {
        tre[i + n] = num[i];
    }
    for (int i = n - 1; i >= 1; i--)
    {
        tre[i] = tre[2 * i] + tre[2 * i + 1];
    }
    vi rv(temp);
    rfo(i, 0, temp)
    {
        cin >> rv[i];
    }
    vi res(temp);
    fo(i, 0, temp)
    {
        int t, a;
        a = rv[i];
        ans = 0;
        search_kth_one(1, 0, n - 1,a);
        res[temp - 1 - i] = ans;
        f(1, 0, n - 1, ans - 1, ans - 1, 0);
    }
    fo(i, 0, temp)
    {
        cout << res[i] << " ";
    }
    cout << endl;
}
int32_t main()
{
    fast;
    int t = 1;
    //  cin >> t;
    fo(i, 1, t + 1)
    {
        solve();
    }
    return 0;
}
