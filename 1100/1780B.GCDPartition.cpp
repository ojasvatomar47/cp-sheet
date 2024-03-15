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
    // can divide the array in k=2 subsegments only and get the max. gcd required
    ll n;
    cin >> n;
    VEC v(n), prefix(n);
    FOR(i, n)
    cin >> v[i],
        prefix[i] = (i) ? (prefix[i - 1] + v[i]) : v[i];

    ll sum = SUM(v), maxi = -1;

    FOR(i, n - 1)
    {
        maxi = max(maxi, __gcd(prefix[i], sum - prefix[i]));
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
/*
Let's note that it doesn't make sense for us to divide into more than k=2 subsegments. Let's prove it.
Let us somehow split the array a into m>2 subsegments : b1,b2,…,bm. Note that gcd(b1,b2,…,bm)≤gcd(b1+b2,b3,…,bm),
since if b1 and b2 were multiples of gcd(b1,b2,…,bm), so b1+b2 is also a multiple of gcd(b1,b2,…,bm).
This means that we can use b1+b2 instead of b1 and b2, and the answer will not worsen, thus it is always beneficial to use no more than k=2 subsegments.
*/