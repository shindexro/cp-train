#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair<int, int> pii;

void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char* x) { cerr << '\"' << x << '\"'; }
void __print(const string& x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }

template <typename T, typename V>
void __print(const pair<T, V>& x)
{
    cerr << '{';
    __print(x.first);
    cerr << ',';
    __print(x.second);
    cerr << '}';
}
template <typename T>
void __print(const T& x)
{
    int f = 0;
    cerr << '{';
    for (auto& i : x)
        cerr << (f++ ? "," : ""), __print(i);
    cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v)
{
    __print(t);
    if (sizeof...(v))
        cerr << ", ";
    _print(v...);
}
#ifndef ONLINE_JUDGE
#define debug(x...)               \
    cerr << "[" << #x << "] = ["; \
    _print(x)
#else
#define debug(x...)
#endif

// segment tree for ranged query, single update, 1-indexed
vector<ll> tree;
const ll ID = 0;

ll f(ll a, ll b)
{
    return gcd(a, b);
}

ll query(int node, int node_low, int node_high, int query_low, int query_high)
{
    if (query_low <= node_low && node_high <= query_high)
        return tree[node];
    else if (node_high < query_low || node_low > query_high)
        return ID;

    int mid = (node_low + node_high) / 2;
    ll left_res = query(node * 2, node_low, mid, query_low, query_high);
    ll right_res = query(node * 2 + 1, mid + 1, node_high, query_low, query_high);
    return f(left_res, right_res);
}

void update(int node, int node_low, int node_high, int query_low, int query_high, int val)
{
    if (query_low <= node_low && node_high <= query_high) {
        tree[node] = val;
        return;
    } else if (node_high < query_low || node_low > query_high)
        return;

    int mid = (node_low + node_high) / 2;
    update(node * 2, node_low, mid, query_low, query_high, val);
    update(node * 2 + 1, mid + 1, node_high, query_low, query_high, val);
    tree[node] = f(tree[node * 2], tree[node * 2 + 1]);
}

int build(vector<ll> a)
{
    int n = a.size();
    while (__builtin_popcount(n) != 1) {
        n++;
        a.push_back(ID);
    }
    tree.resize(2 * n);
    for (int i = 0; i < n; i++)
        tree[n + i] = a[i];
    for (int i = n - 1; i > 0; i--)
        tree[i] = f(tree[i * 2], tree[i * 2 + 1]);

    return n;
}

void solve(int tc)
{
    int n;
    cin >> n;
    vector<ll> v(n);
    for (ll& i : v)
        cin >> i;
    vector<ll> diff;
    for (int i = 1; i < n; i++)
        diff.push_back(abs(v[i] - v[i - 1]));

    int tree_sz = build(diff);

    int ans = 0;
    int left = 1, right = 1;
    while (right <= n - 1) {
        ll fact = query(1, 1, tree_sz, left, right);
        if (fact == 1) {
            left++;
            right = max(left, right);
        } else {
            ans = max(ans, right - left + 1);
            right++;
        }
    }
    cout << ans + 1 << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++)
        solve(t);
}
