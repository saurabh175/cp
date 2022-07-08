#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rfo(i, j, n) for (int i = n - 1; i >= j; i--)
#define fo(i, j, n) for (int i = j; i < n; i++)
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

int32_t main()
{
    int n, m, x, a, b;
    int neg = 0, pos = 0;
    cin >> n >> m;
    while (n--)
    {
        cin >> x;
        if (x == 1)
            pos++;
        else
            neg++;
    }
    while (m--)
    {
        cin >> a >> b;
        if ((b - a + 1) % 2 != 0)
        {
            cout << 0 << endl;
        }
        else
        {
            x = (b - a + 1) / 2;
            if ((neg >= x) and (pos >= x))
            {
                cout << 1 << endl;
            }
            else
                cout << 0 << endl;
        }
    }
    return 0;
}
