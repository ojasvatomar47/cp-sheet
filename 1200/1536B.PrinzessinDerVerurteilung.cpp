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
    // pigeonhole principle: only 1, 2, 3 length substring possible here
    // There are at most n + n−1 + n−2 = 3n−3 possible substrings of length 3 or shorter in the input.
    // There exist 26 + 26^2 + 26^3 = 18278 total substrings of length 3 or shorter.
    // It is impossible for the input to contain all 18278 substrings, as 3n−3 < 18278 for n ≤ 1000.
    ll n;
    cin >> n;
    string str;
    cin >> str;

    // length 1
    for (char ch = 'a'; ch <= 'z'; ch++)
    {
        ll flag = 0;
        FOR(i, n)
        {
            if (str[i] == ch)
            {
                flag = 1;
                break;
            }
        }
        if (!flag)
        {
            print(ch);
            return;
        }
    }

    // length 2
    for (char c1 = 'a'; c1 <= 'z'; c1++)
    {
        for (char c2 = 'a'; c2 <= 'z'; c2++)
        {

            ll i = 0, j = 1, flag = 0;
            while (j < n)
            {
                if (str[i] == c1 && str[j] == c2)
                {
                    flag = 1;
                    break;
                }
                i++, j++;
            }
            if (!flag)
            {
                cout << c1 << c2 << endl;
                return;
            }
        }
    }

    // length 3
    for (char c1 = 'a'; c1 <= 'z'; c1++)
    {
        for (char c2 = 'a'; c2 <= 'z'; c2++)
        {
            for (char c3 = 'a'; c3 <= 'z'; c3++)
            {

                ll i = 0, j = 1, k = 2, flag = 0;
                while (k < n)
                {
                    if (str[i++] == c1 && str[j++] == c2 && str[k++] == c3)
                    {
                        flag = 1;
                        break;
                    }
                }
                if (!flag)
                {
                    cout << c1 << c2 << c3 << endl;
                    return;
                }
            }
        }
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
