#include <bits/stdc++.h>
using namespace std;
//#define int long long
// #define vi vector<int>
// #define vvi vector<vector<int>>
// #define vvc vector<vector<char>>
// #define vs vector<string>
// #define set set<int>
// #define sets set<string>
// #define vp vector<pair<int, int>>
// #define map map<int, int>
#define umap unordered_map<int>
#define pi (3.141592653589)
#define mod 1000000007
#define float double
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define sz size()
#define len length()
#define inf 1e18
#define all(c) c.begin(), c.end()
#define min3(a, b, c) min(c, min(a, b))
#define min4(a, b, c, d) min(d, min(c, min(a, b)))
#define max3(a, b, c) max(c, max(a, b))
#define max4(a, b, c, d) max(d, max(c, max(a, b)))
#define rfo(i, j, n) for (int i = n - 1; i >= j; i--)
#define fo(i, j, n) for (int i = j; i < n; i++)
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

bool isPrime(int n)
{
    if (n == 1)
        return false;
    if (n == 2)
        return true;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

int GCD(int a, int b)
{
    while (b)
    {
        a %= b;
        swap(a, b);
    }
    return a;
}
int LCM(int a, int b)
{
    return (a * b) / GCD(a, b);
}
/*vector<bool> vis(1e6);
vvi g;
int ans,n,m;
bool ok = true;
bool dfs(int u)
{
vis[u] = true;
  for (auto v : g[u])
{
if (!vis[v])
{
if(!dfs(v))return false;
}
}
return true;
};*/
void solve()
{

    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    fo(i, 0, n)
    {
        fo(j, 0, m)
        {
            cin >> grid[i][j];
        }
    }

   vector<vector<int>>dp(n+1,vector<int>(n+1,INT_MAX));
    dp[0][0] = grid[0][0];
    priority_queue<vector<int>> q;
    q.push({-1 * grid[0][0], 0, 0});
    vector<pair<int, int>> v;
    v.push_back({-1, 0});
    v.push_back({1, 0});
    v.push_back({0, 1});
    v.push_back({0, -1});
    while (!q.empty())
    {
        auto node = q.top();
        q.pop();
        int d = -1 * node[0], i = node[1], j = node[2];
        cout << d << " " << i << " " << j << endl;
        for (auto x : v)
        {
            int nx = i + x.first;
            int ny = j + x.second;

            if (nx < 0 || ny < 0 || nx >= n || ny >= n)
                continue;
            cout << nx << " " << ny << " inside " << dp[nx][ny] << endl;
            if (d + grid[nx][ny] < dp[nx][ny])
            {

                dp[nx][ny] = grid[nx][ny] + d;
                cout << dp[nx][ny] << " " << nx << " " << ny << " value" << endl;
                q.push({-1 * dp[nx][ny], nx, ny});
            }
        }
    }
    cout << dp[n - 1][n - 1];
}

//     vvi dist(n, vi(m, INT_MAX));
//     priority_queue<vi> q;
//     dist[0][0] = 0;
//     q.push({0, 0, 0});
//    const vp change = {{0, 1}, {0, 2},{0,0} ,{0, -1}, {0, -2}, {1, 0}, {2, 0}, {-1, 0}, {-2, 0}, {1, 1}, {2, 1}, {1, 2}, {-1, 1}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {1, -1}, {2, -1}, {-1, -1}};
//     while (!q.empty())
//     {
//         int i = q.top()[1], j = q.top()[2], d = q.top()[0];
//         q.pop();

//         for (auto v : change)
//         {
//             int dx = v.ff, dy = v.ss;
//             if (dist[i][j] != -d)
//                 continue;
//             int nx = i + dx, ny = j + dy;
//             if (nx < 0 || ny < 0 || nx >= n || ny >= m)
//                 continue;
//             int cost = ((grid[nx][ny] == '.' && abs(nx - i) + abs(ny - j) <= 1) ? 0 : 1);
//             if (dist[nx][ny] > dist[i][j] + cost)
//             {
//                 dist[nx][ny] = dist[i][j] + cost;
//                 q.push({-dist[nx][ny], nx, ny});
//             }
//         }
//     }
//     cout << dist[n - 1][m - 1] << endl;

int32_t main()
{
    int t = 1;
    // cin >> t;
    fo(i, 1, t + 1)
    {
        solve();
    }
    return 0;
}
