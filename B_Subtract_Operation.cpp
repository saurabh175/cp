#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fo(i, j, n) for (int i = j; i < n; i++)
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

int32_t main()
{
    fast;
    int t = 1;
    cin >> t;
    while (t--)
    {
        long long n, k;
        cin >> n >> k;
        vector<long long> v(n);
        fo(i, 0, n)
        {
            cin >> v[i];
        }
        int flag = 0;
        map<long long, long long> s;
        fo(i, 0, n) s[v[i]]++;
        fo(i, 0, n)
        {
            long long x = v[i] + k;
            if (s.find(x) != s.end())
            {
                flag = 1;
                break;
            }
        }
        if (flag == 1)
        {
            cout << "YES" << endl;
        }
        else
            cout << "NO" << endl;
    }
    return 0;
}
