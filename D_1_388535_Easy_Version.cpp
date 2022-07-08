#include <bits/stdc++.h>
using namespace std;
#define int long long
#define vll vector<int>
#define pi (3.141592653589)
#define mod 1000000007
#define float double
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
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
map<int, int> m0, m1;
map<int, int> am0, am1;
void f(int l, int r)
{
    fo(i, 0, 17)
    {
        fo(j, l, r + 1)
        {
            int x = (j & (1 << i));
            if (x == 0)
            {
                m0[i]++;
            }
            else
            {
                m1[i]++;
            }
        }
    }
}

void solve()
{
    int l, r;
    cin >> l >> r;
    vector<int> v(r - l + 1);
    int x;
    fo(j, 0, r - l + 1)
    {
        cin >> x;
        // cout << x << endl;
        fo(i, 0, 17)
        {
            int y = (x & (1 << i));
            if (y == 0)
            {
                am0[i]++;
                //  cout << " hi 0 comes " << endl;
            }
            else
            {
                am1[i]++;
                //  cout << " hi 1 comes " << endl;
            }
        }
    }
    f(l, r);
    int sum = 0;
    fo(i, 0, 17)
    {
        if (m0[i] != am0[i])
        {
           
            sum += 1 << i;
        }
    }
    cout << sum << endl;
    m0.clear();
    m1.clear();
    am0.clear();
    am1.clear();
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
