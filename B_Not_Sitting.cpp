#include <bits/stdc++.h>
using namespace std;
#define int long long
#define vi vector<int>
#define vc vector<char>
#define vvi vector<vector<int>>
#define vvc vector<vector<char>>
#define vvs vector<vector<string>>
#define vs vector<string>
#define seti set<int>
#define setc set<char>
#define sets set<string>
#define vp vector<pair<int, int>>
#define mapi map<int, int>
#define mapc map<char, int>
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
vector<bool> vis(1e6);
vvi g;
int ans;
int n, m;
void dfs(int u)
{
    vis[u] = true;
    for (auto v : g[u])
    {
        if (!vis[v])
        {
            dfs(v);
        }
    }
}
void solve()
{
    int n, m;
    cin >> n >> m;
    vi v;
    fo(i, 0, n)
    {
        fo(j, 0, m)
        {
            v.pb(max(i, n - i - 1) + max(j, m - j - 1));
        }
    }
    sort(all(v));
    for (auto x : v)
    {
        cout << x<< " ";
    }
    cout << endl;
}
int32_t main()
{
    int t = 1;
    cin >> t;
    fo(i, 1, t + 1)
    {
        solve();
    }
    return 0;
}
// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// #define vll vector<int>
// #define pi (3.141592653589)
// #define mod 1000000007
// #define float double
// #define pb push_back
// #define mp make_pair
// #define ff first
// #define ss second
// #define all(c) c.begin(), c.end()
// #define min3(a, b, c) min(c, min(a, b))
// #define min4(a, b, c, d) min(d, min(c, min(a, b)))
// #define max3(a, b, c) max(c, max(a, b))
// #define max4(a, b, c, d) max(d, max(c, max(a, b)))
// #define rfo(i, j, n) for (int i = n - 1; i >= j; i--)
// #define fo(i, j, n) for (int i = j; i < n; i++)
// #define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

// bool isPrime(int n)
// {
//     if (n == 1)
//         return false;
//     if (n == 2)
//         return true;
//     for (int i = 2; i * i <= n; i++)
//     {
//         if (n % i == 0)
//             return false;
//     }
//     return true;
// }

// int GCD(int a, int b)
// {
//     while (b)
//     {
//         a %= b;
//         swap(a, b);
//     }
//     return a;
// }
// int LCM(int a, int b)
// {
//     return (a * b) / GCD(a, b);
// }
// void dfs(int source, vector<vector<int>> g, int n, map<pair<int, int>, int> &v)
// {

//     vector<int> visited(n + 1, 0);
//     stack<int> s;
//     visited[source] = 1;
//     s.push(source);
//     int current, i = 0;

//     while (!s.empty())
//     {
//         current = s.top();
//         s.pop();

//         for (auto x : g[current])
//         {
//             if (visited[x] == 0)
//             {
//                 i++;
//                 s.push(x);
//                 visited[x] = 1;
//             }
//         }

//         if (!s.empty())
//         {
//             if (i % 2 != 0)
//             {
//                 v[{current, s.top()}] = 2;
//                 v[{s.top(), current}] = 2;
//             }

//             else
//             {
//                 v[{current, s.top()}] = 3;
//                 v[{s.top(), current}] = 3;
//             }
//         }
//     }
// }
// int32_t main()
// {
//     int t = 1;
//     cin >> t;
//     while (t--)
//     {

//         int n, count = 0, max_edge = 0;
//         cin >> n;
//         vector<pair<int, int>> v(n - 1);
//         vector<int> v1(n + 1, 0);
//         vector<vector<int>> g(n + 1);
//         map<pair<int, int>, int> v2;

//         fo(i, 0, n - 1)
//         {
//             cin >> v[i].first >> v[i].second;
//         }
//         fo(i, 0, n - 1)
//         {
//             v1[v[i].first]++;
//             v1[v[i].second]++;
//             g[v[i].first].pb(v[i].second);
//             g[v[i].second].pb(v[i].first);
//         }

//         fo(i, 1, n + 1)
//         {

//             if (v1[i] >= 3)
//             {
//                 max_edge = 3;
//                 break;
//             }
//         }

//         if (max_edge == 3)
//         {
//             cout << -1 << endl;
//         }
//         else if (n == 2)
//         {
//             cout << 2 << endl;
//         }
//         else
//         {

//             int min_length = g[1].size(), source, current, i = 0;
//             fo(i, 2, n + 1)
//             {
//                 if (g[i].size() <= min_length)
//                 {
//                     min_length = g[i].size();
//                     source = i;
//                 }
//             }
//             dfs(source, g, n, v2);
//             fo(i, 0, n - 1)
//             {
//                 cout << v2[{v[i].first, v[i].second}] << " ";
//             }
//             cout << endl;
//         }
//     }
//     return 0;
// }
