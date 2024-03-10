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
    string str1, str2;
    cin >> str1 >> str2;

    // generating all substrings
    vector<string> v1, v2;

    FAB(i, 1, str1.size() + 1)
    {
        ll len = i;

        FOR(j, str1.size())
        {
            string s;
            ll x = min(len * 1ll, str1.size() * 1ll - j);
            FAB(k, j, j + x)
            s.push_back(str1[k]);
            if (s.size() < len)
                continue;
            v1.push_back(s);
        }
    }
    deb(v1);

    FAB(i, 1, str2.size() + 1)
    {
        ll len = i;

        FOR(j, str2.size())
        {
            string s;
            ll x = min(len * 1ll, str2.size() * 1ll - j);
            FAB(k, j, j + x)
            s.push_back(str2[k]);
            if (s.size() < len)
                continue;
            v2.push_back(s);
        }
    }
    deb(v2);

    reverse(v1.begin(), v1.end());
    reverse(v2.begin(), v2.end());

    ll ans = str1.size() + str2.size();

    for (auto &it : v1)
    {
        for (auto &iter : v2)
        {
            if (it == iter)
            {
                ll len = it.size();
                ans = (str1.size() - len) + (str2.size() - len);
                print(ans);
                return;
            }
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
