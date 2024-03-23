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
    // if (ai - aj) % q == 0, then ai % q == aj % q
    // if (ai + aj) % p == 0, then ai % p = (p - (aj % p)) % p
    // thus, here i'm finding the number of elements equal in v2 and at those indices wrt v1 finding the number of pairs in v1 whose sum is equal to 0 / p 
    ll n, p, q;
    cin >> n >> p >> q;
    VEC v1(n), v2(n);
    FOR(i, n)
    {
        ll x;
        cin >> x;
        v1[i] = x % p, v2[i] = x % q;
    }

    // stores the indices of elements equal from v2
    map<ll, vector<ll>> indices;

    FOR(i, n)
    {
        indices[v2[i]].push_back(i);
    }

    ll ans = 0;

    RANGE(indices, it)
    {
        // stores the frequency of the elements with indices equal to the indices at which elements were equal in v2
        map<ll, ll> freq;
        auto v = it.second;
        for (auto &val : v)
            freq[v1[val]]++;

        ll count = 0;

        // finding the number of pairs in the freq map whose sum is equal to p or 0
        for (const auto &pair : freq)
        {
            if (pair.first == 0 || pair.first * 2 == p)
            {
                count += (pair.second * (pair.second - 1) / 2);
                continue;
            }
            ll num = pair.first;
            ll complement = p - num;

            if (complement < num)
                continue; // or break would work as well

            if (freq.find(complement) != freq.end() && freq.at(complement) > 0)
            {
                count += pair.second * freq.at(complement);
            }
        }
        ans += count;
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

// second implementation
// void solve()
// {
//     ll n, p, q;
//     cin >> n >> p >> q;

//     vector<ll> v(n);
//     for (ll i = 0; i < n; i++)
//     {
//         cin >> v[i];
//     }

//     map<pair<ll, ll>, ll> cnt;
//     ll ans = 0;

//     for (auto &ele : v)
//     {
//         ll x = ele % p;
//         ll y = ele % q;

//         pair<ll, ll> key = {(p - x) % p, y};

//         ans += cnt[key];
//         cnt[{x, y}]++;
//     }

//     cout << ans << endl;
// }