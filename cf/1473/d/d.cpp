#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
int tree[500005][3];    // max, min, net

vector<int> query(int a, int b)
{
    vector<int> ret(3);
    a += n; b += n;
    vector<int> idx, ridx;
    while (a <= b) {
        if (a % 2 == 1) {
            idx.push_back(a++);
        }
        if (b % 2 == 0) {
            ridx.push_back(b--);
        }
        a /= 2; b /= 2;
    }
    for (int i : idx) {
        ret[0] = max(ret[0], ret[2] + tree[i][0]);
        ret[1] = min(ret[1], ret[2] + tree[i][1]);
        ret[2] = ret[2] + tree[i][2];
    }
    reverse(ridx.begin(), ridx.end());
    for (int i : ridx) {
        ret[0] = max(ret[0], ret[2] + tree[i][0]);
        ret[1] = min(ret[1], ret[2] + tree[i][1]);
        ret[2] = ret[2] + tree[i][2];
    }
    return ret;            
}

void insert(int k, int x) {
    k += n;
    tree[k][0] = tree[k][1] = tree[k][2] = x;
    for (k /= 2; k >= 1; k /= 2) {
        tree[k][0] = max(tree[2*k][0], tree[2*k][2] + tree[2*k+1][0]);
        tree[k][1] = min(tree[2*k][1], tree[2*k][2] + tree[2*k+1][1]);
        tree[k][2] = tree[2*k][2] + tree[2*k+1][2];
    }
}

void reset() {
    for (int i = 0; i < 500005; i++) {
        tree[i][0] = tree[i][1] = tree[i][2] = 0;
    }
}

void solve(int t)
{
    int m; cin >> n >> m;
    string s; cin >> s;
    reset();
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '-') insert(i, -1);
        else insert(i, 1);
    }

    // auto q = query(0,0);
    // cout << q[0] << " " << q[1] << " " << q[2] << "\n";
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        auto q1 = query(0, a - 2);
        auto q2 = query(b, n - 1);
        int mx = max(q1[0], q1[2] + q2[0]);
        int mn = min(q1[1], q1[2] + q2[1]);
        cout << mx - mn + 1 << "\n";
    }
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
    // freopen("", "r", stdin);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) solve(t);
}

