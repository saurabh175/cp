#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define co 200005
#define int long long int
#define Int int
#define vi vector<int>
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
#define sz(x) ((int)(x).size())
#define loop(n) for (int i = 0; i < n; i++)
#define all(x) (x).begin(), (x).end()
#define trav(it, x) for (auto &it : x)
#define endl "\n"
vector<vi> adj(co);
vector<bool> vis(co);
int check(vi &vp, int t)
{
    int time = vp.size() + 1;
    int req_time = 0;
    int extra = 0;
    priority_queue<int> pq;
    for (int j = vp.size() - 1; j >= 0; j--)
    {

        if (vp[j] > time)
        {
            pq.push(vp[j] - time);
        }

        time--;
    }
    int ans = vp.size() + 1;
    int prev = 0;
    if (!pq.empty())
        prev = pq.top();
    int len = 0;
    return ans + prev;
}
int32_t main()
{

    int T = 1;
    cin >> T;
    while (T--)
    {
        int n, a;
        cin >> n;
        map<int, int> mp;
        for (int i = 2; i <= n; i++)
        {
            cin >> a;
            mp[a]++;
        }
        vector<int> vp;
        for (auto x : mp)
        {
            vp.push_back(x.second);
        }
        sort(all(vp));
        cout << check(vp, 0) << endl;
    }
    return 0;
}