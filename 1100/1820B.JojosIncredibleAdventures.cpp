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
const int N = 1e7 + 5;

void solve()
{
    // just find the max. size of the subarray with all ones in it then check the area for all lengths from 1 to n and breadth from n to 1 respectively
    string str;
    cin >> str;
    ll count = 0, o = 0;
    FOR(i, str.size())
    {
        if (str[i] == '1')
            count++;
        else
            break;
        o += (str[i] == '1');
    }
    reverse(str.begin(), str.end());
    FOR(i, str.size())
    {
        if (str[i] == '1')
            count++;
        else
            break;
    }
    reverse(str.begin(), str.end());

    if (o == str.size())
    {
        print(o * o);
        return;
    }

    deb(count);

    ll flag = 0, maxi = count;
    count = 0;

    FOR(i, str.size())
    {
        if (str[i] == '1')
            count++;
        else
            maxi = max(maxi, count), count = 0;
    }
    maxi = max(maxi, count);

    deb(maxi);

    if (maxi <= 1)
        print(maxi);
    else
    {
        ll n = maxi, x = 1, ans = -1;

        while (n)
        {
            ans = max(ans, n * x);
            n--, x++;
        }
        print(ans);
    }
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
