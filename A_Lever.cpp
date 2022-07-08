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
    int count, flag = 1, temp, leftsum = 0, rightsum = 0;
    string s;
    cin >> s;
    fo(i, 0, s.length())
    {
        if (s[i] == '^')
        {
            count = i;
            break;
        }
    }
    temp = count;
    while (count--)
    {
        if (s[count] != '=')
        {
            leftsum += flag * (s[count] - '0');
            flag++;
        }
        else
            flag++;
    }

    flag = 1;
    while (temp++ < s.length() - 1)
    {
        if (s[temp] != '=')
        {
            rightsum += flag * (s[temp] - '0');
            flag++;
        }
        else
            flag++;
    }

    if (leftsum < rightsum)
        cout << "right" << endl;
    else if (leftsum > rightsum)
    {
        cout << "left" << endl;
    }
    else
        cout << "balance" << endl;
    return 0;
}
