#include <bits/stdc++.h>
using namespace std;

#ifdef ONLINE_JUDGE
#define test(...)
#define deb(...)
#else
#include "deb.h"
#endif

#define ll long long int
#define VEC vector<ll>
#define MAT vector<vector<ll>>
#define PLL pair<ll, ll>
#define PCL pair<char, ll>

// coprime / relatively prime
// O(log(min(a, b)))
ll gcd(ll x, ll y) { return y == 0 ? x : gcd(y, x % y); }
ll lcm(ll x, ll y) { return x / __gcd(x, y) * y; }

#define FAB(i, a, b) for (int i = a; i < b; ++i)
#define RAB(i, a, b) for (int i = a; i > b; --i)
#define FOR(i, n) FAB(i, 0, n)
#define REV(i, n) RAB(i, n - 1, -1)
#define RANGE(v, val) for (auto &val : v)

bool prime(ll a)
{
    if (a == 1)
        return 0;
    for (int i = 2; i * i <= a; ++i)
        if (a % i == 0)
            return 0;
    return 1;
}

template <typename T>
void print(const T &x)
{
    cout << x << endl;
}

template <typename T>
void print(const vector<T> &v)
{
    for (const auto &val : v)
        cout << val << " ";
    cout << endl;
}

#define LINE(str) getline(cin, str, '\n')
#define MIN(v) (*(min_element(v.begin(), v.end())))
#define MAX(v) (*(max_element(v.begin(), v.end())))
#define SUM(v) (accumulate(v.begin(), v.end(), 0ll))
#define CEIL(x, y) ceil((double)x / (double)y)
#define LOWER(v, x) lower_bound(v.begin(), v.end(), x) - v.begin()
#define UPPER(v, x) upper_bound(v.begin(), v.end(), x) - v.begin()
#define yes cout << "YES" << endl
#define no cout << "NO" << endl

const int MOD = 1e9 + 7;
const int N = 1e7 + 5;

void solve()
{
    // just finding how many days can we take all n packets, then n-1 packets, then n-2 packets ...
    ll n, k, ans = 0, ls = 0;
    cin >> n >> k;
    VEC v(n), prefix(n, 0);
    FOR(i, n)
    cin >> v[i];

    sort(v.begin(), v.end());

    FOR(i, n)
    prefix[i] = (i) ? (prefix[i - 1] + v[i]) : v[i];

    deb(k);
    deb(v);
    deb(prefix);

    for (int i = n - 1; i >= 0; i--)
    {
        // ls is the number of days we've already went by
        // ls*(i+1) as we've increased the price by going through those ls days and since we're talking about prefix here so (i+1) times price increases (for the previous i values as well)
        if (prefix[i] + ls * (i + 1) <= k)
        {
            ans += (1 + (k - (prefix[i] + ls * (i + 1))) / (i + 1)) * (i + 1);
            ls += (1 + (k - (prefix[i] + ls * (i + 1))) / (i + 1));
        }
    }
    print(ans);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t, testcase = 1;
    cin >> t;
    while (t--)
    {
        test(testcase++);
        solve();
    }
}
