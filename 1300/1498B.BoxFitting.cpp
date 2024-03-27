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
    // just need to find the max. size of boxes we can fit in and then fit them in
    // can use multiset here for finding the max. sized box which can be fit in our W
    // if no lower_bound (ele >= k) => it == m.end()
    // for simplicity, we can use a multiset as well
    ll n, k;
    cin >> n >> k;
    VEC v(n);
    FOR(i, n)
    {
        cin >> v[i];
    }
    multiset<ll> m(v.begin(), v.end());

    // initialize height as 1
    ll count = 1, maxi = k;

    while (!m.empty())
    {
        // last tick (correct => if(v[mid]<=k))
        auto it = m.lower_bound(maxi);
        if (maxi == *(it))
        {
            maxi -= *(it);
            m.erase(it);
        }
        else
        {
            // it means we don't have any box which we can fit into our BIG BOX
            if (it == m.begin())
            {
                count++, maxi = k;
            }
            // it also covers the case where it == m.end()
            else
            {
                it--;
                maxi -= *(it), m.erase(it);
            }
        }
        deb(m);
    }
    print(count);
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
