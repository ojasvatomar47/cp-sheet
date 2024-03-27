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
    // firstly let's include all the elements in both the subsequences
    // we can form different subsequences with equal OR if we can remove one element from one subsequence and still the OR remains the same
    // so we'll check for each element whether it is possible to remove this element and still make no change to the OR
    // it can only be possible if the set bits of this particular element are also set in atleast one of the other elements
    ll n;
    cin >> n;
    vector<vector<ll>> v;
    map<ll, ll> m;
    FOR(i, n)
    {
        ll k;
        cin >> k;
        VEC temp(k);
        FOR(j, k)
        cin >> temp[j],
            m[temp[j]]++;
        v.push_back(temp);
    }
    deb(v);

    FOR(i, n)
    {
        ll flag = 0;
        FOR(j, v[i].size())
        {
            // checking whether the set bits of this element are already set in other elements or not
            if (m[v[i][j]] - 1 == 0) // or m[v[i][j]] > 1
            {
                flag = 1;
                break;
            }
        }
        if (!flag)
        {
            yes;
            return;
        }
    }
    no;
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