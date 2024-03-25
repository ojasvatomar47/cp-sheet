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
    ll n;
    cin >> n;

    // first considering the elements whose ind >= magnitude of ele
    VEC ind;
    // {ele, ind}
    vector<PLL> ele;
    FOR(i, n)
    {
        ll x;
        cin >> x;
        if ((i + 1) > x)
            ind.push_back(i + 1), ele.push_back({x, i + 1});
    }

    sort(ele.begin(), ele.end());

    n = ind.size();

    // we've already made sure that j>aj and i>ai
    // counting the number of elements whose ind and ele (j and aj) are greater than the current index (i)
    // or we could have just checked whether the aj > i (as we've made sure j>aj so if aj>i then j>i as well)
    // in this case it wasn't necessary to take vector pair for ele array, vector would have worked fine
    ll i = n - 1, j = n - 1, count = 0, last = -1;
    while (i >= 0 && j >= 0)
    {
        // if (ind[i] >= ele[j].first)
        if (ind[i] >= ele[j].first || ind[i] >= ele[j].second)
            i--, count += (n - j - 1);
        else
            j--;
    }
    while (i >= 0)
        count += n, i--;
    print(count);
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
