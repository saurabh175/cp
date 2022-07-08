#include <bits/stdc++.h>
using namespace std;
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <string>
#include <stdio.h>
#define int long long
#define rep(i, n) for (int i = 0; i < n; i++)
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

int f(int x, vector<int> d, vector<int> d1)
{
    if (x > 0)
    {
        if (d[x] == 1)
            return 1;
        else
            return 0;
    }
    else
    {
        if (d1[-1 * x] == 1)
            return 1;
        else
            return 0;
    }
}
int32_t main()
{
    int n, m;
    cin >> n >> m;
    vector<int> r(n, 0);
    vector<int> c(n, 0);
    vector<int> d1(n, 0);
    vector<int> d2(2 * n, 0);
    vector<int> d11(n, 0);

    for (int i = 0; i < m; i++)

    {
        int x, y;
        cin >> x >> y;
       
            if (r[x] == 1 or c[y] == 1 or d2[y + x] == 1 or f(y - x, d1, d11) == 1)
            {
                cout << "NO" << endl;
            }
            else
            {
                cout << "YES" << endl;
                r[x] = 1;
                c[y] = 1;
                d2[y + x] = 1;
                if (y - x > 0)
                {
                    d1[y - x] = 1;
                }
                else
                {
                    d11[x - y] = 1;
                }
            }
        
    }

    return 0;
}
