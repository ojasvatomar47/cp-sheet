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

const int MOD = 998244353;
const int N = 1e7 + 5;

// for caching
vector<ll> dp(2e5 + 7, -1);

ll factorial(ll n)
{
    if (n <= 1)
    {
        return 1;
    }

    if (dp[n] != -1)
    {
        return dp[n];
    }

    dp[0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        dp[i] = (dp[i - 1] * i) % MOD;
    }

    return dp[n];
}

void solve()
{
    // let no of blocks be k (blocks: where equal chars occurs)
    // we need to delete (n-k) chars for alternating string (a)
    // for b we need the product of each block length (since [select len-1 chars from len to delete] (len)C(len-1) = x)
    // multiply this product be (n-k) factorial as we will also consider different arrangements as well
    string str;
    cin >> str;
    ll n = str.size(), count = 1;
    VEC v; // consists of block lengths
    FAB(i, 1, n)
    {
        if (str[i] != str[i - 1])
            v.push_back(count), count = 1;
        else
            count++;
    }
    v.push_back(count);
    deb(v);

    // k denotes no of blocks
    ll a = 0, b = 1, k = v.size();
    FOR(i, v.size())
    {
        a += (v[i] - 1); // we could have simply done a = (n-k)
        b = (b * v[i]) % MOD;
    }
    // for different arrangements
    b = (b * factorial(n - k)) % MOD;
    cout << a << " " << b << endl;
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
