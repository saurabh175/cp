#include <bits/stdc++.h>
using namespace std;

int32_t main()
{
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        string s;
        cin >> s;
        int dx = 0, dy = 0, maxdx = 0, maxdy = 0, mindx = 0, mindy = 0;
        int ansx = 1, ansy = 1;
        for (auto c : s)
        {
            if (c == 'L')
            {
                dy--;
            }
            if (c == 'R')
            {
                dy++;
            }
            if (c == 'U')
            {
                dx--;
            }
            if (c == 'D')
            {
                dx++;
            }
            maxdx = max(dx, maxdx);
            maxdy = max(dy, maxdy);
            mindy = min(dy, mindy);
            mindx = min(dx, mindx);
            int x = n - maxdx;
            int y = m - maxdy;

            if (x >= 1 && x <= n && x + mindx >= 1 && x + maxdx <= n && y >= 1 && y <= m && y + maxdy <= m && y + mindy >= 1)
            {
                ansx = x;
                ansy = y;
            }
            else
            {

                break;
            }
        }
        cout << ansx << " " << ansy << endl;
    }

    return 0;
}
