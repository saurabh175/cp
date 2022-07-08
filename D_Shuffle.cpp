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
int fact(int n);
int nCr(int n, int r)
{
    return fact(n) / (fact(r) * fact(n - r));
}

// Returns factorial of n
int fact(int n)
{
    int res = 1;
    for (int i = 2; i <= n; i++)
        res = res * i;
    return res;
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




int solve2(string &s, int k)
{
	int n = s.size();
	if (!n) return 0;
	int cnt = 0, ans = 0;
	int x = 0;
	int i = 0, j = 0;
	for (; i < n; i++)
	{
		if (s[i] != '1') continue;
		cnt++;
		if (cnt > k)
		{
			x++;
			// print(i, j);
			// calc 
			ans += nCr(i - j, k);
			ans %=mod;
 
			while (cnt > k)
			{
				if (s[j] == '1') cnt--;
				j++;
			}
		}
	}
	if (cnt == k)
	{
		x++;
		// print(i, j);
		// calc
		ans +=nCr(i - j, k);
		ans %=mod;
	}
	return ans;
}
 
void  solve(int tc)
{
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
 
	if (!k) {
        cout<<1<<endl; 
       return; 
    }
	int cnt = 0;
	for (int i = 0; i < n; i++)
		if (s[i] == '1') cnt++;
 
	if (cnt < k) {
       cout<<1<<endl; 
       return;
    } 
 
	int ans = solve2(s, k);
	while (s.size())
	{
		if (s.back() == '1')
		{
			s.pop_back();
			break;
		}
		s.pop_back();
	}
	reverse(all(s));
	while (s.size())
	{
		if (s.back() == '1')
		{
			s.pop_back();
			break;
		}
		s.pop_back();
	}
	reverse(all(s));
	int dc = solve2(s, k - 1);
	ans -= dc;
	ans %=mod;
	if (ans < 0)
		ans +=mod;
	cout<<ans<<endl;
}
 
int32_t main()
{
    int t = 1;

    while (t--)
    {
        solve(t);
    }

    //     int n, k;
    //     cin >> n >> k;
    //     string s;
    //     cin >> s;
    //     int count = 0;
    //     bool ok = false;
    //     int flag = 0;
    //     string s1;
    //     for (auto x : s)
    //     {
    //         if (x == '1')
    //         {
    //             flag++;
    //         }
    //     }
    //     flag = flag - k;
    //     for (int i = 0; i < k; i++)
    //     {
    //         s1 += '1';
    //     }
        

    //     if (k >= 1)
    //     {
    //         if (s.find(s1)<=n-k)
    //         {
    //             ok = true;
    //         }

    //         if (ok)
    //         {
    //             if (k == 1)
    //             {
    //                 cout << n + 2 - flag + 1;
    //             }
    //             else
    //             {
    //                 cout << nCr(n - k + 1, k) + 1;
    //             }
    //         }
    //         else
    //         {
    //             cout << 1 << endl;
    //         }
    //     }
    //     else
    //         cout << 1 << endl;
    // }
    return 0;
}
