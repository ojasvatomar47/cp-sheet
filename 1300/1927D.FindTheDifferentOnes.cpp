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
    // just finding if there has occurred a transition b/w l and r
    ll n;
    cin >> n;
    VEC v(n), hsh(n + 1, 0);
    FOR(i, n)
    cin >> v[i];

    // hsh stores the number of transitions (ie, v[i]!=v[i-1]) occured uptil the ith index
    FAB(i, 2, n + 1)
    {
        hsh[i] = (v[i - 1] != v[i - 2]) + hsh[i - 1];
    }
    deb(hsh);

    ll q;
    cin >> q;
    while (q--)
    {
        ll l, r;
        cin >> l >> r;

        // finding the last index which is equal to hsh[r]-1 (ie, the last place where a transition has occurred b/w l and r)
        ll x = hsh[r] - 1, low = l, high = r, ind = -1;
        while (low <= high)
        {
            ll mid = low + (high - low) / 2;
            if (hsh[mid] <= x)
                low = mid + 1;
            else
                high = mid - 1;
        }
        if (high < l)
            cout << -1 << " " << -1 << endl;
        else
            cout << high << " " << high + 1 << endl;
    }
    cout << endl;
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
