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
    ll n;
    cin >> n;

    // consists of values and days for all the three vectors
    vector<vector<pair<ll, ll>>> v;
    FOR(i, 3)
    {
        vector<pair<ll, ll>> temp(n);
        FOR(j, n)
        cin >> temp[j].first,
            temp[j].second = j;

        // sort each of the 3 arrays in descending order wrt values
        sort(temp.rbegin(), temp.rend());
        v.push_back(temp);
    }

    ll maxi = -1;

    // brute force to find out the max. possible sum st. the days of any two don't coincide
    FOR(i, 3)
    {
        ll v1 = v[0][i].first, d1 = v[0][i].second;
        FOR(j, 3)
        {
            ll v2 = v[1][j].first, d2 = v[1][j].second;
            FOR(k, 3)
            {
                ll v3 = v[2][k].first, d3 = v[2][k].second;
                if (d1 == d2 || d1 == d3 || d2 == d3)
                    continue;
                maxi = max(maxi, v1 + v2 + v3);
            }
        }
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
