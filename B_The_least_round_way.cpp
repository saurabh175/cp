#include <bits/stdc++.h>
using namespace std;
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
int power2(int n)
{
    int count = 0;
    while (n % 2 == 0 && n > 0)
    {
        count++;
        n /= 2;
    }
    return count;
}
int power5(int n)
{
    int count = 0;
    while (n % 5 == 0 && n > 0)
    {
        count++;
        n /= 5;
    }
    return count;
}
void solve()
{

    int n;
    cin >> n;
    vvi v(n + 2, vi(n + 2));
    int r = 0, c = 0;
    int ok = 0;
    fo(i, 1, n + 1)
    {
        fo(j, 1, n + 1)
        {
            cin >> v[i][j];
            if (v[i][j] == 0)
            {
                r = i, c = j;
                ok = 1;
            }
        }
    }

    vvi dp1(n + 1, vi(n + 1));
    vvi dp2(n + 1, vi(n + 1));

    fo(i, 1, n + 1)
    {
        fo(j, 1, n + 1)
        {
            int cost1 = 0, cost2 = 0;
            cost1 = power2(v[i][j]);
            cost2 = power5(v[i][j]);
            dp1[i][j] = cost1 + (i > 1 ? dp1[i - 1][j] : dp1[i][j - 1]);
            dp1[i][j] = min(dp1[i][j], cost1 + (j > 1 ? dp1[i][j - 1] : dp1[i - 1][j]));
            dp2[i][j] = cost2 + (i > 1 ? dp2[i - 1][j] : dp2[i][j - 1]);
            dp2[i][j] = min(dp2[i][j], cost2 + (j > 1 ? dp2[i][j - 1] : dp2[i - 1][j]));
        }
    }
    if (ok == 1)
    {
        cout << min3(dp1[n][n], dp2[n][n], 1) << endl;
        if (min3(dp1[n][n], dp2[n][n],1) >= 1)
        {
            fo(i, 1, r)
            {
                cout << "D";
            }
            fo(i, 1, c)
            {
                cout << "R";
            }
            fo(i, r + 1, n + 1) cout << "D";
            fo(i, c + 1, n + 1) cout << "R";
            cout << endl;
            return;
        }
    }
    else
    {
        cout << min(dp1[n][n], dp2[n][n]) << endl;
    }

    string ans;
    if (dp1[n][n] < dp2[n][n])
    {
        int i = n, j = n;
        while (i > 1 && j > 1)
        {
            if (dp1[i - 1][j] < dp1[i][j - 1])
            {
                ans.pb('D');
                i--;
            }
            else
            {
                ans.pb('R');
                j--;
            }
        }
        while (i > 1)
        {
            ans.pb('D');
            i--;
        }
        while (j > 1)
        {
            ans.pb('R');
            j--;
        }
        reverse(all(ans));
        cout << ans << endl;
    }
    else
    {
        int i = n, j = n;
        while (i > 1 && j > 1)
        {

            if (dp2[i - 1][j] < dp2[i][j - 1])
            {
                ans.pb('D');
                i--;
            }
            else
            {
                ans.pb('R');
                j--;
            }
        }
        while (i > 1)
        {
            ans.pb('D');
            i--;
        }
        while (j > 1)
        {
            ans.pb('R');
            j--;
        }
        reverse(all(ans));
        cout << ans << endl;
    }
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
