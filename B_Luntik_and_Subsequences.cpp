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
int flag;

void solve(int i, int sum, int actualsum, vector<int> v)
{

    if (i >= v.size())
    {
        return;
    }
    if(sum==0){
         for (int j = i; j < v.size(); j++)
        {
            if (v[j] == 0)
            {
                flag++;
            }
        }
        return;
    }
    if (sum == actualsum)
    {
        flag++;

        for (int j = i; j < v.size(); j++)
        {
            if (v[j] == 0)
            {
                flag++;

            }
        }
    }
    if (sum > actualsum)
    {
        return;
    }

    else
    {
        if (i < v.size())
        {
            solve(i + 1, sum + v[i], actualsum, v);
            if(i==v.size()-1&&v[i]==0){

            }
           else  solve(i + 1, sum, actualsum, v);
        }
    }
}
int32_t main()
{
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v;

        int a[n];
        int sum = 0;
        flag = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            v.pb(a[i]);
            sum += a[i];
        }

        if (sum - 1 == 0)
        {
            solve(0, 0, sum - 1, v);
            cout << flag+1  << endl;
        }
        else
        {
            solve(0, 0, sum - 1, v);
            cout << flag << endl;
        }
    }
    return 0;
}
