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

int32_t main()
{
    int n;
    cin >> n;
    vector<int> p(n + 1), b(n + 1);
    unordered_set<int> s;
    int count = 0, sum = 0;
    fo(i, 0, n + 1) cin >> p[i];
    fo(i, 0, n + 1) cin >> b[i];
    fo(i, 0, n + 1)
    {
        if (s.find(p[i]) == s.end())
        {
            s.insert(p[i]);
            count++;
        }
    }
    if (count == n)
    {
        vector<pair<int, int>> ans;
        fo(i, 0, n)
        {
            ans.pb({p[i], b[i]});
        }
        sort(all(ans));
        int flag = 0, min = 0;

        fo(i, 0, n)
        {
            if (ans[i].first == ans[i + 1].first)
            {
                flag = 1;

                if (ans[i].second < ans[i + 1].second)
                {
                    ans[i + 1].second = ans[i].second;
                }
            }
            else
            {
                sum += ans[i].second;

                flag = 0;
            }
        }
        if (flag == 0)
        {
            sum += ans[n].second;
          
            return sum;
        }
    }
    else
    {
        cout << -1 << endl;
        return -1;
    }
    return 0;
}