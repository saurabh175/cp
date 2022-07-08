#include <bits/stdc++.h>
using namespace std;
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <string>
#include <stdio.h>
#define int long long
#define pi (3.141592653589)
#define mod 1000000007
#define int long long
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
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
#define rep(i, n) for (int i = 0; i < n; i++)
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

int32_t main()
{
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        string s;
        cin >> s;
        vector<int> b, r;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'B')
            {
                b.push_back(v[i]);
            }
            else
                r.push_back(v[i]);
        }
        sort(all(b));
        sort(all(r));
        int cur = 1;
        bool ans = true;
        for (int i = 0; i < b.size(); i++)
        {
            if (b[i] >= cur)
            {
                cur++;
            }
            else
            {
                ans = false;
                break;
            }
        }
        for (int i = 0; i < r.size(); i++)
        {
            if (r[i] <= cur)
            {
                cur++;
            }
            else
            {
                ans = false;
                break;
            }
        }
        if (ans == true)
        {
            cout << "YES" << endl;
        }
        else
            cout << "NO" << endl;
    }
    return 0;
}
