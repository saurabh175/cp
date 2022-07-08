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
        vector<int> a(n, 0);
        vector<int> ans;
        vector<int> cnt(32, 0);
        rep(i, n) cin >> a[i];
        rep(i, 32)
        {
            rep(j, n)
            { 
               
                if ((a[j] & (1 << (i))))
               
                    cnt[i]++;
            }
        }
        rep(i, n)
        {
            bool ok = true;
            rep(j, 32)
            {
                if (cnt[j] % (i+1) != 0)
                {
                    ok = false;
                    break;
                }
            }
            if (ok)
                ans.push_back(i + 1);
        }
        for (auto x : ans)
            cout << x << " ";
        cout << endl;
    }
    return 0;
}
