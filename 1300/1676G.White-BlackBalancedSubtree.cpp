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
    // from n to 1, finding the number of black and whites involved in that subtree
    // using dp here (colors), ie, using the value of the previously calculated subtree's colors for finding the b and w of the current subtree

    ll n, count = 0;
    cin >> n;

    VEC v(n + 1, 1);
    FAB(i, 2, n + 1)
        cin >> v[i];

    string str;
    cin >> str;

    // basic subtree (just the hashed one)
    vector<vector<ll>> tree(n + 1);

    FAB(i, 2, n + 1)
    {
        tree[v[i]].push_back(i);
    }
    deb(tree);

    // {black, white} (dp)
    vector<pair<ll, ll>> colors(n + 1);

    for (int i = n; i >= 1; i--)
    {
        ll b = (str[i - 1] == 'B'), w = (str[i - 1] == 'W');
        FOR(j, tree[i].size())
        {
            // using the previously computed values
            b += (colors[tree[i][j]].first), w += (colors[tree[i][j]].second);
        }
        colors[i] = {b, w};
        if (b == w)
            count++;
    }
    deb(colors);
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


/*
    parent-child subtrees' creation (assuming 1 is the root node):
    vector<vector<ll>> tree(n + 1);
 
    FAB(i, 2, n + 1)
    {
        ll ind = i;
        while (ind != 1)
        {
            tree[v[ind]].push_back(i);
            ind = v[ind];
        }
    }
    deb(tree);
*/