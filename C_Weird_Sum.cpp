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
bool comp(pair<int, int> &p1, pair<int, int> &p2)
{
    return (p1.second < p2.second);
}
void solve()
{
    int n, c, x;
    cin >> n >> c;
    map<int, vector<pair<int, int>>> m;
    fo(i, 1, n + 1)
    {
        fo(j, 1, c + 1)
        {
            cin >> x;
            if (m[x].size() == 0)
            {
                vector<pair<int, int>> v;
                v.pb({i, j});
                m[x] = v;
            }
            else
                m[x].pb({i, j});
        }
    }
    int sum = 0, flag = 0, curr, count;
    for (auto x : m)
    {
        sort(all(x.second));
        count = 0, curr = 0;

        int l = x.second.size();
        int i = 1;

        for (auto y : x.second)
        {
            count += y.first * (l - i);
            i++;
        }
        int j = l;
        for (auto y : x.second)
        {
            curr += y.first * (l - j);
            j--;
        }
        sum += abs(curr - count);
    }
    for (auto x : m)
    {
        flag = 0;
        sort(all(x.second), comp);
        count = 0, curr = 0;

        int l = x.second.size();
        int i = 1;

        for (auto y : x.second)
        {
            count += y.second * (l - i);
            i++;
        }
        int j = l;
        for (auto y : x.second)
        {
            curr += y.second * (l - j);
            j--;
        }
        sum += abs(curr - count);
    }
    cout << sum << endl;
}
int32_t main()
{
    int t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}
