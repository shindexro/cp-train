#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
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

template <typename T>
class Segtree {
private:
    vector<T> tree;
    int leaves;

public:
    T identity;
    T(*f)
    (T a, T b);

    Segtree(T identity, T (*f)(T, T))
    {
        this->identity = identity;
        this->f = f;
    }

    T query(int node, int node_low, int node_high, int query_low, int query_high)
    {
        if (query_low <= node_low && node_high <= query_high)
            return tree[node];
        else if (node_high < query_low || node_low > query_high)
            return identity;

        int mid = (node_low + node_high) / 2;
        ll left_res = query(node * 2, node_low, mid, query_low, query_high);
        ll right_res = query(node * 2 + 1, mid + 1, node_high, query_low, query_high);
        return f(left_res, right_res);
    }

    T query(int query_low, int query_high)
    {
        return query(1, 0, leaves - 1, query_low, query_high);
    }

    void update(int node, int node_low, int node_high, int query_idx, int val)
    {
        if (node_low == query_idx && node_high == query_idx) {
            tree[node] = val;
            return;
        } else if (node_high < query_idx || node_low > query_idx)
            return;

        int mid = (node_low + node_high) / 2;
        update(node * 2, node_low, mid, query_idx, val);
        update(node * 2 + 1, mid + 1, node_high, query_idx, val);
        tree[node] = f(tree[node * 2], tree[node * 2 + 1]);
    }

    void update(int query_idx, int val)
    {
        update(1, 0, leaves - 1, query_idx, val);
    }

    void build(vector<T> a)
    {
        leaves = a.size();
        while (__builtin_popcount(leaves) != 1) {
            leaves++;
            a.push_back(identity);
        }
        tree.resize(2 * leaves);
        for (int i = 0; i < leaves; i++)
            tree[leaves + i] = a[i];
        for (int i = leaves - 1; i >= 1; i--)
            tree[i] = f(tree[i * 2], tree[i * 2 + 1]);
    }
};

void solve(int tc)
{
    int n, m;
    cin >> n >> m;
    vector<string> cav(n);
    for (string& s : cav)
        cin >> s;

    vector<bool> block(m + 1);
    for (int i = 0; i < m - 2; i++) {
        for (int j = 0; j < n - 2; j++) {
            bool ok = true;
            for (int a = i; a < i + 3; a++) {
                for (int b = j; b < j + 3; b++) {
                    if (cav[b][a] == '.') {
                        ok = false;
                        break;
                    }
                }
            }
            block[i] = ok || block[i];
        }
    }

    Segtree<bool> st(false, [](bool a, bool b) { return a || b; });
    st.build(block);

    int q;
    cin >> q;

    while (q--) {
        int l, r;
        cin >> l >> r;

        if (st.query(l, r - 2)) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    for (int t = 1; t <= T; t++)
        solve(t);
}
