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
    // if the item can conquer the next item, it can also conquer all the elements conquered by the next item as well (otherwise it can just conquer the elements before it)
    ll n;
    cin >> n;
    vector<PLL> vp(n), res(n);
    FOR(i, n)
    cin >> vp[i].first,
        vp[i].second = i;
    sort(vp.begin(), vp.end());

    res[n - 1] = {n - 1, vp[n - 1].second};

    VEC prefix(n);
    prefix[0] = vp[0].first;

    FAB(i, 1, n)
    prefix[i] = prefix[i - 1] + vp[i].first;

    deb(prefix);

    for (int i = n - 2; i >= 0; i--)
    {
        if (prefix[i] >= vp[i + 1].first)
            res[i] = {res[i + 1].first, vp[i].second};
        else
            res[i] = {i, vp[i].second};
    }

    // deb(res);

    sort(res.begin(), res.end(), [](const pair<ll, ll> &a, const pair<ll, ll> &b)
         { return (a.second != b.second) ? (a.second < b.second) : (b.first > a.first); });

    for (auto &it : res)
        cout << it.first << " ";
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
