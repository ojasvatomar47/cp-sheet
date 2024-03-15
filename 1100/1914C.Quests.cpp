#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define VEC vector<ll>
#define MAT vector<vector<ll>>
#define PLL pair<ll, ll>
#define PCL pair<char, ll>

ll gcd(ll x, ll y) { return y == 0 ? x : gcd(y, x % y); }
ll lcm(ll x, ll y) { return x / gcd(x, y) * y; }

#define FAB(i, a, b) for (int i = a; i < b; ++i)
#define RAB(i, a, b) for (int i = a; i > b; --i)
#define FOR(i, n) FAB(i, 0, n)
#define REV(i, n) RAB(i, n - 1, -1)
#define RANGE(v, val) for (auto &val : v)

bool prime(ll a)
{
    if (a == 1)
        return 0;
    for (int i = 2; i <= round(sqrt(a)); ++i)
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
    {
        cout << val << " ";
    }
    cout << endl;
}

template <typename T, typename U>
void print(const vector<pair<T, U>> &v)
{
    for (const auto &val : v)
    {
        cout << val.first << " " << val.second << endl;
    }
}

#define LINE(str) getline(cin, str, '\n')
#define MIN(v) (*(min_element(v.begin(), v.end())))
#define MAX(v) (*(max_element(v.begin(), v.end())))
#define yes cout << "YES" << endl
#define no cout << "NO" << endl

const int MOD = 1e9 + 7;
const int N = 1e7 + 5;

void solve()
{
    // greedy ...
    ll n, k, s = 0;
    cin >> n >> k;
    vector<PLL> vp(n);
    FOR(i, n)
    {
        ll x;
        cin >> x, s += x, vp[i].first = s;
    }
    FOR(j, n)
    cin >> vp[j].second;
    ll lim = min(n, k), maxi = vp[0].second, ans = -INT_MAX;
    FOR(i, lim)
    {
        maxi = max(maxi, vp[i].second),
        ans = max(ans, vp[i].first + (k - (i + 1)) * maxi);
    }
    print(ans);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}