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
struct node
{
    int l, r, c;
} ;
int32_t main()
{
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<node> v(n);

        fo(i, 0, n) cin >> v[i].l >> v[i].r >> v[i].c;
        int Min = v[0].l, Max = v[0].r;
        int mincost = v[0].c;
        int maxcost = 0;
        cout<<mincost<<endl;
        maxcost=mincost;
        fo(i, 1, n)
        {
            if (v[i].l > Min && v[i].r > Max)
            {
                cout<<mincost+v[i].c<<endl;
                Max=v[i].r;
                maxcost=mincost+v[i].c;
            }
          
             else if (v[i].l > Min && v[i].r >= Max)
            {
                cout<<mincost+v[i].c<<endl;
                Max=v[i].r;
                 maxcost=mincost+v[i].c;
            }
          
            else if (v[i].l == Min && v[i].r > Max){
                cout<<v[i].c<<endl;
                Max=v[i].r;
                 maxcost=v[i].c;
            }

            else if (v[i].l == Min && v[i].r < Max){
                cout<<maxcost<<endl;
               
            }
            else{
                cout<<maxcost<<endl;
            }
        }
    }
    return 0;
}
