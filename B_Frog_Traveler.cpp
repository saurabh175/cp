#include <bits/stdc++.h>
using namespace std;
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <string>
#include <stdio.h>
#define int long long
#define pi (3.141592653589)
#define mod 1000000007
#define int long long
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
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
#define rep(i, n) for (int i = 0; i < n; i++)
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
vector<int> maxans;
int jump = 0;
int maxjump = INT_MAX;
void solve(int n, int x, vector<int> &a, vector<int> &b, vector<int> ans)
{
    if (x <= 0)
    {
        if (maxjump > jump){
       
            maxjump = jump;
            maxans = ans;
        }   
        return;
    }
    else
    {
        for (int i = 0; i <= a[x - 1]; i++)
        {
        
            ans.pb(x - i);
            x -= i;
            jump++;
            if (x <= 0)
            {
                solve(n, x, a, b, ans);
             
                x += i;
                jump--;
             if(!ans.empty()) ans.pop_back();
            }
            else if (i - b[x - 1] > 0)
            {
                x += b[x - 1];
                solve(n, x, a, b, ans);
               
                jump--;
                if(!ans.empty()) ans.pop_back();
                x-=b[x-1];
                 x += i;
            }
            else
            {
                x += i;
                if(!ans.empty()) ans.pop_back();
                jump--;
            }
        }
    }
}
int32_t main()
{
    int t = 1;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> b(n);
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }

        solve(n, n, a, b, ans);
     
        if (maxjump != INT_MAX)
        {
            cout << maxjump << endl;
            for (auto x : maxans)
            {
                cout << x << " ";
            }
            cout << endl;
        }
        else
            cout << "-1" << endl;
    }
    return 0;
}
