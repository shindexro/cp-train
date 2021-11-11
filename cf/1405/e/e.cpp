#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

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
    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    vector<int> pre(n + 1), req(n);
    vector<tuple<int, int, int, int, int>> ins; // val, instruction_type, low, high, ref
    for (int i = 0; i < n; i++) {
        if (i + 1 - pre[i] <= v[i] && v[i] <= i + 1) {
            pre[i + 1] = pre[i] + 1;
            req[i] = i + 1 - v[i];
        } else {
            pre[i + 1] = pre[i];
            req[i] = n + 1;
        }
        ins.push_back({ req[i], 1, i, i, i });
    }

    for (int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;
        ins.push_back({ pre[x], 2, x, n - 1 - y, i });
    }
    sort(ins.begin(), ins.end());

    Segtree<int> st(0, [](int a, int b) { return a + b; });
    st.build(vector<int>(n));

    vector<int> ans(q);
    for (int i = 0; i < ins.size(); i++) {
        auto& [val, type, low, high, idx] = ins[i];
        cerr << val << " " << type << " " << low << " " << high << " " << idx << "\n";

        if (type == 1) {
            st.update(idx, 1);
        } else {
            ans[idx] = st.query(low, high);
        }
    }

    for (int a : ans) {
        cout << a << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    for (int t = 1; t <= T; t++) {
        solve(t);
    }
}
