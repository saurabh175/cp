#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)

int main()
{
    int tc;
    scanf("%d", &tc);
    while (tc--)
    {
        int n;
        scanf("%d", &n);
        vector<int> a(n);
        forn(i, n) scanf("%d", &a[i]);
        long long ans = 1e18;
        int mx = *max_element(a.begin(), a.end());
        for (int x : {mx, mx + 1})
        {
            long long cnt1 = 0, cnt2 = 0;
            forn(i, n)
            {
                cnt2 += (x - a[i]) / 2;
                cnt1 += (x - a[i]) % 2;
            }
            long long thd = 2 * cnt2 + cnt1;
            if (cnt1 > cnt2)
            {
                ans = min(ans, (cnt1 * 2 - 1));
            }
            else
            {
                long long cans = 0;
                long long l = 0, r = cnt2;
                while (l < r)
                {
                    long long mid = (l + r) / 2;
                    if (3 * mid >= thd)
                    {
                        ans = min(ans, mid * 2);
                        r = mid;
                    }
                    else if (3 * mid + 1 >= thd)
                    {
                        ans = min(ans, mid * 2 + 1);
                        r = mid;
                    }
                    else
                    {
                        l = mid+1;
                    }
                }
                ans = min(ans, cnt2 * 2);
            }
        }
        printf("%lld\n", ans);
    }
}