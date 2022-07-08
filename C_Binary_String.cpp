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
void solve()
{
    string s;
    cin >> s;
    int cnt0 = 0, cnt1 = 0;
    for (auto x : s)
    {
        if (x == '0')
            cnt0++;
        else
            cnt1++;
    }
    int remove1 = min(cnt0, cnt1);
    int start = 0, end = s.sz - 1;
    if (remove1 == 0)
    {
        cout << 0 << endl;
    }
    else
    {
        fo(i, 0, s.sz)
        {
            if (s[i] == '0')
            {
                cnt0--;
                start = i + 1;
            }
            else
            {
                break;
            }
        }
        rfo(i, 0, s.sz)
        {
            if (s[i] == '0')
            {
                cnt0--;
                end = i - 1;
            }
            else
            {
                break;
            }
        }
        // cout << cnt0 << " " << cnt1 << endl;
        // cout << start << " " << end << endl;
        remove1 = min(cnt0, cnt1);
        int n = s.sz;
        if (remove1 == 0)
        {
            cout << "0" << endl;
        }
        else
        {
            int ans = 0;
            while (start < end)
            {
                int dec0 = 0, dec1 = 0;
                for (int i = start + 1; i < n && s[i] != '1'; i++)
                {
                    dec0++;
                }
                for (int i = end - 1; s[i] != '1' && i >= 0; i--)
                {
                    dec1++;
                }
                if (dec0 < dec1)
                {
                    end -= dec1;
                    end--;
                    cnt0 -= dec1;
                    ans++;
                }
                else
                {
                    start += dec0;
                    start++;
                    cnt0 -= dec0;
                    ans++;
                }
                if (ans < cnt0)
                {
                    continue;
                }
                else
                {
                    break;
                }
            }
            cout << ans << endl;
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
