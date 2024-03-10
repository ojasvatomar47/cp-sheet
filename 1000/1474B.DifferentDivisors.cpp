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
// const int N = 1e7 + 5;

const int N = 1e7 + 10;
vector<bool> primeCheck(N, 1);

// n/2 + n/3 + n/4 + .... + n/n : tc: O(n*logn)
// n/2 + n/3 + n/5 + n/7 + .... : tc: O(n*log(logn))

void seive()
{
    primeCheck[0] = primeCheck[1] = false;
    for (int i = 2; i < N; i++)
    {
        if (primeCheck[i] == true)
        {
            for (int j = 2 * i; j < N; j += i)
                primeCheck[j] = false;
        }
    }
}

void solve()
{
    ll d;
    cin >> d;

    ll x = 1 + d;
    deb(x);

    while (primeCheck[x] != true)
        x++;

    ll y = x + d;
    while (primeCheck[y] != true)
        y++;

    print(x * y);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    seive();

    ll t, testcase = 1;
    cin >> t;
    while (t--)
    {
        test(testcase++);
        solve();
    }
}
