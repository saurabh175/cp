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
int32_t main()
{
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        fo(i, 0, n)
        {
            cin >> a[i];
        }
        string s;
        cin >> s;
        int count = 1;
        int flag = 0;
        for (auto x : s)
        {
            if (x == '1')
            {
                flag++;
            }
        }
        if (flag == s.length())
        {
            fo(i, 0, n)
            {
                cout << a[i] << " ";
            }
            cout << endl;
        }
        else
        {
            set<pair<int,int>> m;
            set<pair<int,int>> p;
            fo(i, 0, s.length())
            {
                if (s[i] == '0')
                {
                    m.insert({a[i], i});
                }
            }
            fo(i, 0, s.length())
            {
                if (s[i] == '1')
                {

                    p.insert({a[i], i});
                }
            }

            for (auto x : m)
            {
                a[x.second] = count++;
            }
            for (auto x : p)
            {
                a[x.second] = count++;
            }
            fo(i, 0, n)
            {
                cout << a[i] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
