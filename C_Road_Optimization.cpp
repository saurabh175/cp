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

bool c(pair<int, int> v, pair<int, int> v1)
{
    return (v.second > v1.second);
}
int32_t main()
{
    int n, l, k, a, b = 0, temp;
    cin >> n >> l >> k;
    vector<pair<int, int>> v(n);
    fo(i, 0, n)
    {

        cin >> a;
        v[i].first = a;
    }
    fo(i, 0, n)
    {
        cin >> a;
        v[i].second = a;
    }

    fo(i, 0, n)
    {
        if (i + 1 == n)
        {
            b += v[i].second * (l - v[i].first);
        }
        else
            b += v[i].second * (v[i + 1].first - v[i].first);
    }
    int count = 0;
    fo(i, 0, k)
    {
        temp = b;
        fo(j, 1, n)
        {
            if (j - i >= 1 && (v[j - i - 1].second < v[j - i].second))
            {
                if (j + 1 != n)
                {
                    if (b > temp - (v[j - i].second - v[j - 1 - i].second) * (v[j + 1 - i].first - v[j - i].first))
                    {
                        b = temp - (v[j - i].second - v[j - 1 - i].second) * (v[j + 1 - i].first - v[j - i].first);
                        //   v.erase(v.begin() + j - i);
                        count = j;
                    }
                }
                else
                {
                    if (b > temp - (v[j - i].second - v[j - 1 - i].second) * (l - v[j - i].first))
                    {
                        b = temp - (v[j - i].second - v[j - 1 - i].second) * (l - v[j - i].first);
                        //v.erase(v.begin() + j - i);
                        count = j;
                    }
                }
            }
        }
        v.erase(v.begin() + count - i);
    }

    cout << b << endl;
    return 0;
}
