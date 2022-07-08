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
int32_t main()
{
    string s1, s2, ans;
    int a, b;
    cin >> a >> b;
    int sum = a + b;
    ans = to_string(sum);
    s1 = to_string(a);
    s2 = to_string(b);

    char ch = '0';
    while (ans.find(ch) <= ans.length())
    {
        ans.erase(ans.find(ch), 1);
    }

    while (s2.find(ch) <= s2.length())
    {
        s2.erase(s2.find(ch), 1);
    }

    while (s1.find(ch) <= s1.length())
    {
        s1.erase(s1.find(ch), 1);
    }
    a = stoi(s1);
    b = stoi(s2);
    sum = a + b;
    s1 = to_string(sum);
    if (s1 == ans)
    {
        cout << "YES" << endl;
    }
    else
        cout << "NO" << endl;
    return 0;
}
