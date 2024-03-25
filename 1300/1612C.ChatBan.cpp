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
    // need to find the largest n in n*(n+1)/2 <= m
    // can apply binary search with low=1 and high=2*k-1
    // and apply ap formula of sum to find the number of emotes till mid and then compare it with m
    ll k, m;
    cin >> k >> m;

    // 2 * (k * (k + 1) / 2) - k => total sum of all the emotes for all the 2*k-1 messages = (k * k)
    if ((k * k) <= m)
    {
        print(2 * k - 1);
        return;
    }

    ll low = 1, high = 2 * k - 1;
    while (low <= high)
    {
        ll mid = low + (high - low) / 2, x;
        if (mid <= k)
            x = mid * (mid + 1) / 2;
        else
        {
            if (mid == 2 * k - 1)
                x = (k * k);
            else
                x = (k * k) - ((2 * k - 1 - mid) * (2 * k - mid) / 2);
        }
        if (x < m)
            low = mid + 1;
        else
            high = mid - 1;
    }
    print(high + 1);
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
