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
    // all columns diff independent with each other
    // also we need to find the sum of difference b/w all the elements in the array (abs difference -> thus the array's order does not matter much)
    // to find the sum of diff b/w all the elements in an array:
    // 1) Sort the array and then find prefix sum from the last element
    // 2) ans += (prefix[i+1] - ai*(n-i-1)) where (n-i-1) denotes the number of elements from i to n and prefix[i+1] denotes the sum of those elements
    ll n, m, ans = 0;
    cin >> n >> m;
    vector<vector<ll>> v(n, vector<ll>(m, 0));
    FOR(i, n)
    {
        FOR(j, m)
        cin >> v[i][j];
    }

    FOR(i, m)
    {
        VEC temp(n), prefix(n, 0);
        FOR(j, n)
        temp[j] = v[j][i];
        sort(temp.begin(), temp.end());

        for (int j = n - 1; j >= 0; j--)
            prefix[j] = (j == n - 1) ? (temp[j]) : (prefix[j + 1] + temp[j]);

        FOR(j, n - 1)
        {
            ans += (prefix[j + 1] - (n - j - 1) * temp[j]);
        }
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
