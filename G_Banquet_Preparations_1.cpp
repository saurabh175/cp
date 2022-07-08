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
        vector<vector<int>> v(n, vector<int>(2, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                cin >> v[i][j];
            }
        }
        int balance = 0, minsofor = INT_MAX, minx, j, mini, minj, sub;
        for (int i = 0; i < n; i++)
        {
            minx = min(v[i][0], v[i][1]);
            sub = v[i][0] + v[i][1] - m;
            minsofor = INT_MAX;
            for (int i = 0; i <= min(sub, minx); i++)
            {
                if (abs(2 * i - sub) < minsofor)
                {
                    minsofor = abs(2 * i - sub);

                    mini = i;
                    minj = sub - i;
                }
            }
            balance +=minsofor;
            if (v[i][0] < v[i][1])
            {
                v[i][0] = v[i][0] - mini;
                v[i][1] = v[i][1] - minj;
            }
            else
            {
                v[i][0] = v[i][0] - minj;
                v[i][1] = v[i][1] - mini;
            }
        }
        cout << balance << endl;
        for (int i = 0; i < n; i++)
        {
            cout << v[i][0] << " " << v[i][1] << endl;
            ;
        }
    }
    return 0;
}
