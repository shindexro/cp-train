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

    T query(int node, int node_low, int node_high, int query_idx)
    {
        if (node_low == query_idx && node_high == query_idx)
            return tree[node];
        else if (node_high < query_idx || node_low > query_idx)
            return identity;

        int mid = (node_low + node_high) / 2;
        ll left_res = query(node * 2, node_low, mid, query_idx);
        ll right_res = query(node * 2 + 1, mid + 1, node_high, query_idx);
        return tree[node] + f(left_res, right_res);
    }

    T query(int query_idx)
    {
        return query(1, 0, leaves - 1, query_idx);
    }

    void update(int node, int node_low, int node_high, int query_low, int query_high, int val)
    {
        if (query_low <= node_low && node_high <= query_high) {
            tree[node] += val;
            return;
        } else if (node_high < query_low || node_low > query_high)
            return;

        int mid = (node_low + node_high) / 2;
        update(node * 2, node_low, mid, query_low, query_high, val);
        update(node * 2 + 1, mid + 1, node_high, query_low, query_high, val);
    }

    void update(int query_low, int query_high, int val)
    {
        update(1, 0, leaves - 1, query_low, query_high, val);
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
    }
};

void solve(int _t)
{
    int n, q;
    cin >> n >> q;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    Segtree<ll> st(0ll, [](ll a, ll b) { return a + b; });
    st.build(a);

    for (int i = 0; i < q; i++) {
        int type;
        cin >> type;
        if (type == 1) {
            int a, b, u;
            cin >> a >> b >> u;
            a--;
            b--;
            st.update(a, b, u);
        } else {
            int k;
            cin >> k;
            k--;
            cout << st.query(k) << "\n";
        }
    }
}

int main()
{
    solve(0);
    return 0;
}
