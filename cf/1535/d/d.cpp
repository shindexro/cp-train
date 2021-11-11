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

#define N (int)(1 << 19)
vector<int> shift(N), unshift(N);

void update(vector<int>& tree, string& s, int i)
{
    int j = shift[i];
    if (s[i] == '0') {
        tree[j] = tree[j * 2];
    } else if (s[i] == '1') {
        tree[j] = tree[j * 2 + 1];
    } else {
        tree[j] = tree[j * 2] + tree[j * 2 + 1];
    }
    if (j > 1)
        update(tree, s, unshift[j / 2]);
}

void setup(int i, int depth)
{
    int cur = i;
    int level = depth - 1;
    int interval = 1 << (depth - 1);
    while (cur >= interval) {
        level--;
        cur -= interval;
        interval >>= 1;
    }
    int j = (1 << level) + cur;
    shift[i] = j;
    unshift[j] = i;
}

void solve(int tc)
{
    int k;
    cin >> k;
    string s;
    cin >> s;
    int n = s.size();

    vector<int> tree(1 << k << 1);
    for (int i = 1 << k; i < 1 << k << 1; i++)
        tree[i] = 1;
    for (int i = 0; i < n; i++)
        setup(i, k);
    for (int i = 0; i < n; i++)
        update(tree, s, i);

    int q;
    cin >> q;
    while (q--) {
        int p;
        char c;
        cin >> p >> c;
        p--;
        s[p] = c;
        update(tree, s, p);
        cout << tree[1] << "\n";
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
