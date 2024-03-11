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
    ll n;
    cin >> n;

    VEC v(n);
    FOR(i, n)
        cin >> v[i];

    deb(v);

    ll x = -1, y = -1;

    FOR(i, n / 2)
    {
        if (v[i] != v[n - i - 1])
        {
            x = v[i], y = v[n - i - 1];
            break;
        }
    }

    deb(x, y);

    if (x == -1)
    {
        yes;
        return;
    }

    VEC v1, v2;

    FOR(i, n)
    {
        if (v[i] != x)
            v1.push_back(v[i]);
        if (v[i] != y)
            v2.push_back(v[i]);
    }

    deb(v1);
    deb(v2);

    ll flag = 0;

    FOR(i, v1.size())
    {
        if (v1[i] != v1[v1.size() - i - 1])
        {
            flag = 1;
            break;
        }
    }

    if (!flag)
    {
        yes;
        return;
    }

    flag = 0;

    FOR(i, v2.size())
    {
        if (v2[i] != v2[v2.size() - i - 1])
        {
            flag = 1;
            break;
        }
    }

    if (!flag)
    {
        yes;
        return;
    }
    no;
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
