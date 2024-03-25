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
    // given sorted array
    // for each i, we'll try to take the subsequence i, i-1, i-2, ...
    // since we need max score, v[i]>=1, v[i-1]>=2, v[i-2]>=3, v[i-3]>=4 .... (since dividing by d! means we would divide by a number each time we take a new element)
    // if this inequality fails this means that now the score will be multiplied by 0.something which would make our score smaller
    // our ans for each i would be the max. elements we could take with the above inequality
    ll n;
    cin >> n;
    VEC v(n + 1, 0);
    FAB(i, 1, n + 1)
    cin >> v[i];

    FAB(i, 1, n + 1)
    {
        if (i == 1)
            cout << 1 << " ";
        else
        {
            // finding the smallest element which would satisfy our inequality
            ll low = 1, high = i - 1;
            while (low <= high)
            {
                ll mid = low + (high - low) / 2;
                if (v[mid] >= i - mid + 1)
                    high = mid - 1;
                else
                    low = mid + 1;
            }
            cout << i - low + 1 << " ";
        }
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
