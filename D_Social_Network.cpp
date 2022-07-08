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
int co;
int dfs(int x, vector<int> v[], vector<bool> &vis, int n)
{

    if (!vis[x])
    {
        co++;
        vis[x] = true;
        for (auto y : v[x])
        {
            dfs(y, v, vis, n);
        }
    }
    return co;
}
void path(int x, int z, vector<int> v[], vector<bool> &vis,bool &ok)
{
    if (!vis[x])
    {
        vis[x] = true;
        for (auto y : v[x])
        {
            if (y == z)
            {
                ok=true;
            }
            path(y, z, v, vis,ok);
        }
    }
}
int32_t main()
{
    int n, d, m = 1;
    cin >> n >> d;
    vector<bool> vis(n, false);
    vector<int> v[n + 1];
    int flag = 0;
    while (d--)
    {
        bool ok=false;
        vector<bool> v2(n, false);
        vector<bool> v3(n, false);
        int x, y;
        cin >> x >> y;
         path(x, y, v, v3,ok);
        if (!vis[x] && !vis[y])
        {
            if (flag >= 1)
            {
                v[x].push_back(y);
                v[y].push_back(x);
                vis[x] = vis[y] = true;
                cout << m + 1 << endl;
                m = m + 1;  
            }
            else
            {
                v[x].push_back(y);
                v[y].push_back(x);
                vis[x] = vis[y] = true;
                cout << m << endl;
            }
        }
       
        else if (ok)
        { 
            flag++; 
            m = m + 1;
            cout << m << endl;
        }

        else
        {
            vis[x] = vis[y] = true;
            v[x].push_back(y);
            v[y].push_back(x);
            co = -1;
            int z = dfs(x, v, v2, n);
            if (z >= m)
            {
                cout << z << endl;
                m = z;
            }
            else
                cout << m << endl;
        }
    }

    return 0;
}
#include <bits/stdc++.h>
// #include <sys/resource.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
 
// Pragmas
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
 
// Aliases
using ll = long long;
using ull = unsigned long long;
using ld = long double;
// template<typename T>
// using oset =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
// Constants
constexpr ll INF = 2e18;
constexpr ld EPS = 1e-9;
constexpr ll MOD = 1e9 + 7;
 
// Macros
#define F first
#define S second
#define all(x) begin(x), end(x)
#define allr(x) rbegin(x), rend(x)
#define int long long
 
// Custom hash map
struct custom_hash
{
    static uint64_t splitmix64(uint64_t x)
    {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
 
    size_t operator()(uint64_t x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
template <typename T1, typename T2> // Key should be integer type
using safe_map = unordered_map<T1, T2, custom_hash>;
 
// Operator overloads
template<typename T1, typename T2> // cin >> pair<T1, T2>
istream& operator>>(istream &istream, pair<T1, T2> &p) { return (istream >> p.first >> p.second); }
template<typename T> // cin >> vector<T>
istream& operator>>(istream &istream, vector<T> &v) { for (auto &it : v) cin >> it; return istream; }
template<typename T1, typename T2> // cout << pair<T1, T2>
ostream& operator<<(ostream &ostream, const pair<T1, T2> &p) { return (ostream << p.first << " " << p.second); }
template<typename T> // cout << vector<T>
ostream& operator<<(ostream &ostream, const vector<T> &c) { for (auto &it : c) cout << it << " "; return ostream; }
 
// Utility functions
template <typename T>
void print(T &&t)  { cout << t << "\n"; }
template <typename T, typename... Args>
void print(T &&t, Args &&... args)
{
    cout << t << " ";
    print(forward<Args>(args)...);
}
 
template <typename T>
int32_t size_i(T &container) { return static_cast<int32_t>(container.size()); }
 
// Mathematical functions
int GCD(int a, int b) {
    while (b)
    {
        a %= b;
        swap(a, b);
    }
    return a;
}
int GCD_extended(int a, int b, int &x, int &y) {
    x = 1, y = 0;
    int x1 = 0, y1 = 1, a1 = a, b1 = b;
    while (b1)
    {
        int q = a1 / b1;
        tie(x, x1) = make_tuple(x1, x - q * x1);
        tie(y, y1) = make_tuple(y1, y - q * y1);
        tie(a1, b1) = make_tuple(b1, a1 - q * b1);
    }
    return a1;
}
int LCM(int a, int b)
{
    return ((ll)a * b) / GCD(a, b);
}
 
ll modpow(ll x, ll n, int m = MOD)
{
    if (x == 0 && n == 0) return 0; // undefined case
    ll res = 1;
    while (n > 0) 
    {
        if (n % 2)
            res = (res * x) % m;
        x = (x * x) % m;
        n /= 2;
    }
    return res;
}
 
int modinv(int x, int m = MOD)
{   
    return modpow(x, m - 2, m);
}
 
mt19937 rng;
int getRandomNumber(int l, int r)
{
    uniform_int_distribution<int> dist(l, r);
    return dist(rng);
}
 
//////////////////////////////////////////////////// START CODE HERE /////////////////////////////////////////////////////////////
 
void preSolve()
{
    rng = mt19937(chrono::steady_clock::now().time_since_epoch().count());
    // allocateStackMax();
    
}
 
multiset<int> sz;
int extra = 1;
 
class DSU
{
private:
    vector<int> parent, size;
public:
    DSU(int n)
    {
        parent = vector<int>(n);
        size = vector<int>(n, 1);
        iota(begin(parent), end(parent), 0);
    }
    
    int getParent(int x)
    {
        if (parent[x] == x) return x;
        return parent[x] = getParent(parent[x]);
    }
 
    void join(int x, int y)
    {
        x = getParent(x);
        y = getParent(y);
        if (size[x] > size[y])
            swap(x, y);
        if (x == y)
        {
            extra++;
            return;
        }
 
        sz.erase(sz.find(-size[x]));
        sz.erase(sz.find(-size[y]));
 
        parent[x] = y;
        size[y] += size[x];
 
        sz.insert(-size[y]);        
    }
 
    int getSize(int x)
    {
        return size[x] = size[getParent(x)];
    }
};
 
void solve(int tc)
{
    int n, d;
    cin >> n >> d;
    for (int i = 1; i <= n; i++)
        sz.insert(-1);
 
    DSU dsu(n + 1);
    for (int i = 1; i <= d; i++)
    {
        int u, v;
        cin >> u >> v;
        dsu.join(u, v);
        int ans = 0, cnt = 0;
        for (auto it = sz.begin(); cnt < extra; it++, cnt++)
            ans += -(*it);
        print(ans - 1);
    }
}
 
int32_t main()  
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(12) << fixed;
 
    preSolve();
    int tests = 1;
    // cin >> tests;
    for (int tt = 1; tt <= tests; tt++)
        solve(tt);
    return 0;
}
