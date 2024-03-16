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
    string str1, str2;
    cin >> str1 >> str2;
    VEC temp, zeroes(n, 0), ones(n, 0);

    FOR(i, n)
    {
        zeroes[i] = (i) ? (zeroes[i - 1] + (str1[i] == '0')) : (str1[i] == '0');
        ones[i] = (i) ? (ones[i - 1] + (str1[i] == '1')) : (str1[i] == '1');
    }

    // deb(zeroes);
    // deb(ones);

    ll flag = 0;

    for (int i = n - 1; i >= 0; i--)
    {
        // same
        if (flag)
        {
            if (str1[i] == str2[i])
            {
                temp.push_back(i);
                flag = 0;
            }
        }
        // different
        else
        {
            if (str1[i] != str2[i])
            {
                temp.push_back(i);
                flag = 1;
            }
        }
    }
    // deb(temp);

    if (str1[0] == str2[0])
    {
        if (flag)
        {
            no;
            return;
        }
    }
    if (str1[0] != str2[0])
    {
        if (!flag)
        {
            no;
            return;
        }
    }

    FOR(i, temp.size())
    {
        if (zeroes[temp[i]] != ones[temp[i]])
        {
            no;
            return;
        }
    }
    yes;
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
