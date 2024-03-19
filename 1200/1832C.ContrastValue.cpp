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
    // finding the number of increasing and decreasing subsegments and the answer would be count + 1
    // in an increasing/decreasing subsegment the sum of absolute diff b/w adjacent elements is equal to the absolute diff b/w the first and the last element 
    ll n, c = 1, j = 0;
    cin >> n;
    VEC v;
    map<ll, ll> m;
    FOR(i, n)
    {
        ll x;
        cin >> x;
        if (!i)
            v.push_back(x);
        else if (v[v.size() - 1] != x)
            v.push_back(x);
    }
    n = v.size();

    if (n <= 2)
    {
        print(n);
        return;
    }

    deb(v);

    ll flag = (v[1] > v[0]); // inc

    FAB(i, 2, n)
    {
        // inc
        if (flag)
        {
            // dec
            if (v[i] < v[i - 1])
                c++, flag = 0;
        }
        // dec
        else
        {
            // inc
            if (v[i] > v[i - 1])
                c++, flag = 1;
        }
    }
    print(c + 1);
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
