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
    // circular list, sort differences in descending order, each day 2*day number of days affected in those differences (since virus from both ends)
    ll n, m;
    cin >> n >> m;
    VEC v(m), diff;
    FOR(i, m)
    cin >> v[i];
    sort(v.begin(), v.end());
    FAB(i, 1, m)
    {
        diff.push_back(v[i] - v[i - 1] - 1);
    }

    diff.push_back(v[0] - 1 + n - v[m - 1]);

    sort(diff.rbegin(), diff.rend());

    deb(diff);

    ll day = 0, count = 0;

    FOR(i, diff.size())
    {
        ll x = diff[i] - 2 * day;
        if (x > 0)
            count += (x == 1) ? 1 : (x - 1), day += 2;
            // if x!=1, we're increasing days by 2 as we're putting two barricates to save the houses (start, end), thus 2 days will pass by
            // in case of x==1, after this day, we cannot save any day, since day inc and diff dec, thus x dec more, so inc days by 2 won't do us any harm
    }
    print(n - count);
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
