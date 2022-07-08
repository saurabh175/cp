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
void solve()
{
    string s, s1, s2;
    cin >> s;
    int count = 0;
    set<char> m;
    int j = 0;
    int i = 0;
    if (s.length() == 1)
    {
        cout << 1 << endl;
        return;
    }
    for (i = 0; i < s.length() - 1; i++)
    {
        if (s[i] == s[i + 1] && m.find(s[i]) == m.end()||(i==s.length()-2&&s[i] == s[i + 1]))
        {
            // cout << "inside " << endl;
            if (i != j)
            {
                count += i - j;
            }

            i++;
            j = i + 1;
            m.clear();
        }
        else
        {
            if (m.find(s[i]) != m.end())
            {
                if (j == 0)
                {
                    count += i - j;
                    count--;
                }
                else
                    count += i - j - 1;
                j = i + 1;
                m.clear();
            }
            else
            {
                m.insert(s[i]);
            }
        }
    }
    if (m.find(s[i]) != m.end())
    {
        //  cout << "hi" << endl;

        count += i - j;
        count--;

        j = i + 1;
        m.clear();
    }
    else if (i != j)
    {
        // cout << "bi ";
        count += i - j + 1;
    }
    else if (s[i] == s[i - 1] && s[i - 1] == s[i - 2])
    {
        // cout << "ni";
        count++;
    }
    else if (s[s.length() - 1] != s[s.length() - 2])
    {
        count++;
    }
    cout << count << endl;
}
int32_t main()
{
    
    int t = 1;
    cin >> t;  
    while (t--)
    {
        solve();
        
    }
    return 0;
}
