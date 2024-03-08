#include <bits/stdc++.h>
using namespace std;

#ifdef ONLINE_JUDGE
#define test(...)
#define deb(...)
#else
#include "./deb.h"
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

ll bS(vector<ll> &v, ll n, ll k, ll l, ll h)
{
    ll low = l, high = h;
    while (low <= high)
    {
        ll mid = low + (high - low) / 2;
        if (v[mid] >= k)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return (low <= h) ? low : -1;
}

void solve()
{
    ll n, maxi = -1;
    char ch;
    cin >> n >> ch;
    string str;
    cin >> str;
    VEC greens;
    FOR(i, n)
    if (str[i] == 'g')
        greens.push_back(i);
    deb(greens);

    FOR(i, n)
    {
        if (str[i] == ch)
        {
            ll ans = bS(greens, greens.size(), i, 0, greens.size() - 1);
            deb(ans);
            if (ans == -1)
                maxi = max(maxi, n - i + greens[0]);
            else
                maxi = max(maxi, greens[ans] - i);
        }
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
