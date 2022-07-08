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
void solve()
{
    vector<vector<int>> v(3, vector<int>(4, 0));
    vector<int> ans(4, 0);
    int x;

    fo(i, 0, 3)
    {
        fo(j, 0, 4)
        {
            cin >> x;
            v[i][j] = x;
        }
    }
    int a, b, c, d;
    a = min3(v[0][0], v[1][0], v[2][0]);
    b = min3(v[0][1], v[1][1], v[2][1]);
    c = min3(v[0][2], v[1][2], v[2][2]);
    d = min3(v[0][3], v[1][3], v[2][3]);
    if (a + b + c + d < 1000000)
    {
        cout << "IMPOSSIBLE" << endl;
    }
    else
    {
        ans[0] = a;
        if (a + b <= 1000000)
        {
            ans[1] = b;
            if (a + b + c <= 1000000)
            {
                ans[2] = c;
                if (a + b + c + d == 1000000)
                {
                    ans[3] = d;
                }
                else
                {
                    ans[3] = 1000000 - a - b - c;
                }
            }
            else
            {
                ans[2] = 1000000 - a - b;
            }
        }
        else
        {
            ans[1] = 1000000 - a;
        }
        cout << ans[0] << " " << ans[1] << " " << ans[2] << " " << ans[3] << endl;
    }
}
int32_t main()
{
    int t = 1;
    cin >> t;
    fo(i, 1, t + 1)
    {
        cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}
