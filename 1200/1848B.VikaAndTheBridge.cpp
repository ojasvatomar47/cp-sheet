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
    // implementation question
    // need to find two largest steps for each color and paint the largest step b/w the two
    // then find the max b/w both the steps again
    // do this for each color and find the min of the largest steps taken for each color
    ll n, k;
    cin >> n >> k;

    // stores the steps taken by each color to go to it's next occurence
    vector<vector<ll>> temp(k + 1);

    // last stores the last indices of the ith color
    VEC v(n), last(k + 1, -1);

    FOR(i, n)
    {
        cin >> v[i];
        if (last[v[i]] == -1)
            last[v[i]] = i, temp[v[i]].push_back(i);
        else
            temp[v[i]].push_back(i - last[v[i]] - 1), last[v[i]] = i;
    }

    // steps to reach to the end from the last occurence of each color
    FAB(i, 1, k + 1)
    {
        temp[i].push_back(n - last[i] - 1);
    }

    // sort the steps for each colors in descending order
    FAB(i, 1, k + 1)
    sort(temp[i].rbegin(), temp[i].rend());

    ll mini = INT_MAX;

    FAB(i, 1, k + 1)
    {
        if (temp[i].size() > 1)
        {
            // color the middle step b/w the two largest steps of the ith color and then find the max b/w the two
            ll maxi = max(temp[i][0] / 2, temp[i][1]);

            // this maxi could be our ans
            mini = min(mini, maxi);
        }
    }
    print(mini);
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
