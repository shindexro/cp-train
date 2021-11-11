#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

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

void solve(int _t)
{
    int n, q;
    cin >> n >> q;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    // Segtree<ll> st(0ll, [](ll a, ll b) { return a + b; });
    // Segtree<ll> st(LLONG_MAX, [](ll a, ll b) { return min(a, b); });
    Segtree<ll> st(0, [](ll a, ll b) { return a ^ b; });
    st.build(a);

    for (int i = 0; i < q; i++) {
        int type, x, y;
        cin >> x >> y;
        type = 2;
        if (type == 1) {
            st.update(x - 1, y);
        } else {
            cout << st.query(x - 1, y - 1) << "\n";
        }
    }
}

int main()
{
    solve(0);
    return 0;
}
