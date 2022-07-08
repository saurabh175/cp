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

string xoring(string a, string b, int n)
{
    string ans = "";

    // Loop to iterate over the
    // Binary Strings
    for (int i = 0; i < n; i++)
    {
        // If the Character matches
        if (a[i] == b[i])
            ans += "0";
        else
            ans += "1";
    }
    return ans;
}
int32_t main()
{
    int t = 1;
    cin >> t;
    int count;
    string x, y;
    while (t--)
    {
        int n, k;
        string s;
        cin >> n >> k >> s;
        count = 0;
        int ro=0;
        fo(i,0,n-k+1)ro^=(s[i]-'0');
        if(ro==1)count++;
        int start=0,last=n-k+1;
        while(last<n)
        {
        ro^=s[start++]-'0';
        ro^=s[last++]-'0';
        if(ro==1)count++;
         
        }
        cout << count << endl;
    }
    return 0;
}
