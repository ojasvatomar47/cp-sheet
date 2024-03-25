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
    // for each ith bit and a specific k, we can either unset k bits or no bits
    // so for each ith bit (bits array), we can check if we can unset all the bits by decreasing set bits k times (bits[i]%k==0)
    // if it is possible, this k would work else this k won't work
    ll n;
    cin >> n;

    // bits consists of no of elements with the (31-i-1)th bit set
    VEC v(n), bits(31, 0);
    FOR(i, n)
    {
        cin >> v[i];
        ll x = v[i], count = 30;
        while (x)
        {
            bits[count--] += (x & 1);
            x >>= 1;
        }
    }
    deb(bits);

    FAB(i, 1, n + 1)
    {
        ll flag = 0;
        FOR(j, 31)
        {
            if (bits[j] % i)
            {
                flag = 1;
                break;
            }
        }
        if (!flag)
            cout << i << " ";
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
