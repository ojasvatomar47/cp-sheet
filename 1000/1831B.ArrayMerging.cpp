#include <bits/stdc++.h>
using namespace std;

#ifdef ONLINE_JUDGE
#define test(...)
#define deb(...)
#else
#include "./deb.h"
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
    ll n, maxi = -1;
    cin >> n;
    VEC v1(n), v2(n), hsh1(2 * n + 1, 0), hsh2(2 * n + 1, 0);

    FOR(i, n)
    cin >> v1[i];
    FOR(i, n)
    cin >> v2[i];

    ll i = 0, j = 1;

    while (j < n)
    {
        if (v1[i] == v1[j])
            j++;
        else
        {
            hsh1[v1[i]] = max(hsh1[v1[i]], j - i);
            i = j, j++;
        }
    }
    hsh1[v1[i]] = max(hsh1[v1[i]], j - i);

    i = 0, j = 1;

    while (j < n)
    {
        if (v2[i] == v2[j])
            j++;
        else
        {
            hsh2[v2[i]] = max(hsh2[v2[i]], j - i);
            i = j, j++;
        }
    }
    hsh2[v2[i]] = max(hsh2[v2[i]], j - i);

    deb(hsh1);
    deb(hsh2);

    FOR(i, 2 * n + 1)
    {
        maxi = max(maxi, hsh1[i] + hsh2[i]);
    }
    print(maxi);
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