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
    // used an extra array to memorize for getting info about the last - 2nd operation which was conducted
    ll n, q, flag = 0, sum = 0, ele = -1;
    cin >> n >> q;
    VEC v(n), mark(n, 0);
    FOR(i, n)
        cin >> v[i],
        sum += v[i];

    // flag denotes the number of 2nd op conducted uptil now (helps in checking with the marked array)

    while (q--)
    {
        ll t;
        cin >> t;
        // 1st op
        if (t == 1)
        {
            ll ind, x;
            cin >> ind >> x;

            // 2nd op hasn't been conducted uptil now (simple)
            if (!flag)
            {
                sum = sum - v[ind - 1] + x;
                print(sum);
                v[ind - 1] = x;
            }
            // 2nd op has been conducted
            else
            {
                // if any change on ind hasn't been conducted yet, after the last - 2nd op
                // thus using the element which was inserted during the last - 2nd op
                if (mark[ind - 1] != flag)
                {
                    sum = sum - ele + x, mark[ind - 1] = flag, v[ind - 1] = x;
                    print(sum);
                }
                // if atleast one change on ind has been conducted after the last - 2nd op
                // thus using the element from the array now
                else
                {
                    sum = sum - v[ind - 1] + x;
                    print(sum);
                    v[ind - 1] = x;
                }
            }
        }
        // 2nd op
        else
        {
            ll x;
            cin >> x;
            cout << x * n << endl;
            sum = x * n, flag++, ele = x;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // ll t, testcase = 1;
    // cin >> t;
    // while (t--)
    {
        // test(testcase++);
        solve();
    }
}
