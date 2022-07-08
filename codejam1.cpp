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
bool palindrom(int n)
{
    if (n < 10)
    {
        return true;
    }
    else
    {
        int p = n;
        string s = "", s1;
        while (n)
        {
            s += (n % 10 + '0');
            n /= 10;
        }
        int ans = 0;
        fo(i, 0, s.len)
        {
            ans += (s[i] - '0') * (int)pow(10, s.len - i - 1);
        }
        if (ans == p)
            return true;
        else
            return false;
    }
}
void Divisors(int n)
{
    int count = 0;

    for (int i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {

            if (n / i == i)
            {
                if (palindrom(i))
                {
                    count++;
                }
            }
            else
            {
                if (palindrom(i))
                    count++;
                if (palindrom(n / i))
                    count++;
            }
        }
    }
    cout << count << endl;
}

void solve()
{
    int n, p;
    cin >> n >> p;
    int x, prv = 0;
    int sum = 0;
    int a, b;
    fo(i, 0, n)
    {
        a = 1000000000000, b = (-1 * a);
        fo(j, 0, p)
        {
            cin >> x;
            if (x > b && x != prv)
            {

                b = max(b, x);
            }
            if (x < a)
            {
                a = min(a, x);
            }
        }
        if (i == 0)
        {
            sum += a;
        }
        if (i > 0)
        {
            sum += abs(prv - a);
        }
        if (b > prv)
        {
            sum += abs(b - a);
            prv = b;
        }
        else
            prv = a;
    }
    cout << sum << endl;
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
