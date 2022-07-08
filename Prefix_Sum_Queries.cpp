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

int N = 300500;
int n;
struct node
{
    int seg;
    int suf;
    int prf;
    int sum;
};
vector<node> tree;
node f(int si, int sl, int sr, int ql, int qr, int v)
{
    if (ql <= sl && sr <= qr)
    {
        if (v != INT_MAX)
        {
            if (v >= 0)
                tree[si].seg = tree[si].suf = tree[si].prf = tree[si].sum = v;
            else
            {
                tree[si].seg = tree[si].suf = tree[si].prf = 0;
                tree[si].sum = v;
            }
        }
        node s;
        s.prf = tree[si].prf;
        s.sum = tree[si].sum;
        s.suf = tree[si].suf;
        s.seg = tree[si].seg;
        return s;
    }
    if (sr < ql || sl > qr)
    {
        node s;
        s.prf = s.sum = s.seg = s.suf = 0;
        return s;
    }
    int mid = sl + (sr - sl) / 2;
    node l, r, res;
    l = f(2 * si, sl, mid, ql, qr, v);
    r = f(2 * si + 1, mid + 1, sr, ql, qr, v);
    res.sum = l.sum + r.sum;
    res.prf = max(l.prf, l.sum + r.prf);
    res.suf = max(r.suf, r.sum + l.suf);
    res.seg = max3(l.seg, r.seg, l.suf + r.prf);
    tree[si].sum = tree[2 * si].sum + tree[2 * si + 1].sum;
    tree[si].prf = max(tree[2 * si].prf, tree[2 * si].sum + tree[2 * si + 1].prf);
    tree[si].suf = max(tree[2 * si + 1].suf, tree[2 * si + 1].sum + tree[2 * si].suf);
    tree[si].seg = max3(tree[2 * si].seg, tree[2 * si + 1].seg, tree[2 * si].suf + tree[2 * si + 1].prf);
    return res;
}

void solve()
{
    int q;
    cin >> n >> q;
    vi num(n);
    fo(i, 0, n)
    {
        cin >> num[i];
    }
    while (__builtin_popcount(n) != 1)
    {
        n++;
        num.pb(0);
    }
    tree.resize(2 * n);
    for (int i = 0; i < n; i++)
    {
        if (num[i] >= 0)
            tree[i + n].seg = tree[i + n].suf = tree[i + n].prf = tree[n + i].sum = num[i];
        else
        {
            tree[i + n].seg = tree[i + n].suf = tree[i + n].prf = 0;
            tree[n + i].sum = num[i];
        }
    }
    for (int i = n - 1; i >= 1; i--)
    {
        tree[i].sum = tree[2 * i].sum + tree[2 * i + 1].sum;
        tree[i].prf = max(tree[2 * i].prf, tree[2 * i].sum + tree[2 * i + 1].prf);
        tree[i].suf = max(tree[2 * i + 1].suf, tree[2 * i + 1].sum + tree[2 * i].suf);
        tree[i].seg = max3(tree[2 * i].seg, tree[2 * i + 1].seg, tree[2 * i].suf + tree[2 * i + 1].prf);
    }
    cout << f(1, 0, n - 1, 0, n - 1, INT_MAX).seg << endl;
    while (q--)
    {
        int t, a, b;
        cin >> a >> b;
        f(1, 0, n - 1, a, a, b);
        cout << f(1, 0, n - 1, 0, n - 1, INT_MAX).seg << endl;
    }
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
