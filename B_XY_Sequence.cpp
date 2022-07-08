#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fo(i, j, n) for (int i = j; i < n; i++)
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

int32_t main()
{
    int t = 1;
    cin >> t;
    while (t--)
    {
        long long n, b, x, y;
        cin >> n >> b >> x >> y;
        long long sum = 0;
        vector<long long> v(n+1);
        v[0] = 0;
        fo(i, 1, n + 1)
        {
            long long k = v[i - 1] + x;
            long long l = v[i - 1] - y;
            if (k <= b)
            {
                v[i] = k;
                sum += v[i];
            }
            else
            {
                v[i] = l;
                sum += v[i];
            }
        }
        cout << sum << endl;
    }
    return 0;
}
