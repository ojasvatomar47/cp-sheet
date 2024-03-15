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
    // since we need to divide equal no. of boxes in trucks, we can think of divisors of total number of boxes
    // then find the sum of all the numbers withing those divisors range using prefix sum of the array
    
    ll n, maxi = 0, ans = -1e18;
    cin >> n;
    VEC v(n);
    FOR(i, n)
    cin >> v[i];
    // sort(v.begin(), v.end());

    VEC prefix(n);

    FOR(i, n)
    prefix[i] = (i) ? (prefix[i - 1] + v[i]) : v[i];

    deb(prefix);

    VEC divs;

    for (int i = 1; i * i <= n; i++)
    {
        if (!(n % i))
        {
            divs.push_back(i);
            if (n / i != i)
                divs.push_back(n / i);
        }
    }

    sort(divs.begin(), divs.end());

    FOR(j, divs.size())
    {
        ll d = divs[j], maxi = -1e18, mini = 1e18;

        for (int i = d - 1; i < n; i += d)
        {
            ll curr = (i != d - 1) ? prefix[i] - prefix[i - d] : prefix[i];

            maxi = max(maxi, curr), mini = min(mini, curr);
        }

        ans = max(ans, maxi - mini);
    }
    print(ans);
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