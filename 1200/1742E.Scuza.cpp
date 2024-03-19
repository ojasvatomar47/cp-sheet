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
    // just need to find how many numbers are less than v2[i] in v1[i] (can count them using sliding window)
    ll n, q;
    cin >> n >> q;
    VEC v(n), prefix(n, 0);
    FOR(i, n)
        cin >> v[i],
        prefix[i] = (i) ? (prefix[i - 1] + v[i]) : v[i];
    vector<PLL> vp(q);
    FOR(i, q)
        cin >> vp[i].first,
        vp[i].second = i;

    sort(vp.begin(), vp.end());

    ll i = 0, j = 0, count = 0;

    while (i < n && j < q)
    {
        ll ele = vp[j].first, ind = vp[j].second;

        if (v[i] <= ele)
            count++, i++;
        else
            vp[j].first = count, j++;
    }

    while (j < q)
        vp[j++].first = count;

    sort(vp.begin(), vp.end(), [](const pair<ll, ll> &a, const pair<ll, ll> &b)
         { return (a.second != b.second) ? (a.second < b.second) : (b.first > a.first); });

    FOR(k, q)
    {
        ll ind = vp[k].first - 1;
        if (ind == -1)
            cout << 0 << " ";
        else
            cout << prefix[ind] << " ";
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
