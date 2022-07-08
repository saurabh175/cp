#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>     // Including tree_order_statistics_node_update
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;

typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
vector<int> nums;
void solve()
{

    int n;
    cin >> n;
    nums.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    ordered_set os;
    vector<int> ret(n);
    for (int i = nums.size() - 1; i >= 0; i--)
    {
        ret[i] = os.order_of_key(nums[i]);
        os.insert(nums[i]);
    }
    for (auto x : os)
    {
        cout << x << " ";
    }
    cout << endl;
    for (auto x : ret)
    {
        cout << x << " ";
    }
    cout << endl;
}
int32_t main()
{
    // fast;
    int t = 1;
    // cin >> t;
    for (int i = 0; i < t; i++)
    {
        solve();
    }
    return 0;
}
