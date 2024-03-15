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
    // two types of ops -> delete two from beg. / one from the end. can make a prefix type array and if x type of 1st op, then k-x type of second op.
    ll n, k;
    cin >> n >> k;
    VEC v(n);
    FOR(i, n)
    cin >> v[i];
    sort(v.begin(), v.end());
    deb(v);

    ll sum = SUM(v), l = 0;
    VEC v1, v2;
    v1.push_back(v[0] + v[1]);
    FAB(i, 2, n - 1)
    v1.push_back(v1[l++] + v[i] + v[i + 1]),
        i++;
    v2 = v;
    reverse(v2.begin(), v2.end());
    FAB(i, 1, n)
    v2[i] += v2[i - 1];
    deb(v1);
    deb(v2);

    ll maxi = sum - v2[k - 1];
    deb(maxi);
    FOR(i, k)
    {
        ll s, x = k - (i + 1) - 1;
        if (x < 0)
            s = sum - v1[i];
        else
            s = sum - v1[i] - v2[x];
        maxi = max(maxi, s);
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
