#include <bits/stdc++.h>
using namespace std;
#define int long long

#define fo(i, j, n) for (int i = j; i < n; i++)

#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

int32_t main()
{
    int t = 1;
    cin >> t;
    while (t--)
    {
        int w, h;
        cin >> w >> h;
        int k;
        int Min, Max;
        int cost, maxcost = INT_MIN;

        fo(i, 0, 2)
        {
            cin >> k;
            vector<int> v(k);
            fo(i, 0, k)
            {
                cin >> v[i];
            }
            Min = v[0];
            Max = v[k - 1];
            cost = Max - Min;
            maxcost = max(cost, maxcost);
        }
        int maxarea = (maxcost * h);
        maxcost = INT_MIN;

        fo(i, 0, 2)
        {
            cin >> k;
            vector<int> v(k);
            fo(i, 0, k)
            {
                cin >> v[i];
            }
            Min = v[0];
            Max = v[k - 1];
            cost = Max - Min;
            maxcost = max(cost, maxcost);
        }
        maxarea = max(maxarea, (maxcost * w));
        cout << maxarea << endl;
    }
    return 0;
}
