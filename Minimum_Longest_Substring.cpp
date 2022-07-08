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

void solve()
{
    int n;
    cin >> n;
    string s, even, odd;
    cin >> s;
    string temp = s, str = "";
    for (auto x : s)
    {
        if ((x - '0') % 2 == 0)
        {
            even.pb(x);
        }
        else
            odd.pb(x);
    }

    if (even.size() > odd.size())
    {
        sort(all(temp));
        int x = even.size() / (odd.size() + 1);

        if (even.size() % (odd.size() + 1) >=odd.size())
        {
            x++;
        }
        string s1 = "";
        fo(i, 0, x)
        {
            s1 += '0';
        }
        fo(i, 0, odd.size())
        {
            str += s1;
            str += '1';
        }
        int z = x * odd.size();
        int y = even.size() - z;
        int i = 0;
        while (i++ < y)
        {
            str += '0';
        }
        cout << temp << endl;
        cout << str << endl;
    }
    else
    {
        sort(all(temp), greater<int>());
        int x = odd.size() / (even.size() + 1);
        if (odd.size() % (even.size() + 1) >= even.size())
        {
            x++;
        }
        string s1 = "";
        fo(i, 0, x)
        {
            s1 += '1';
        }
        fo(i, 0, even.size())
        {
            str += s1;
            str += '0';
        }

        int z = x * even.size();
        int y = odd.size() - z;
        int i = 0;
        while (i++ < y)
        {
            str += '1';
        }
        cout << temp << endl;
        cout << str << endl;
    }
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
