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

void solve(int tc)
{
    int n;
    cin >> n;
    vector<int> v(n);
    set<int> want;
    for (int& i : v) {
        cin >> i;
        want.insert(i);
    }

    cout << want.size() << "\n";

    vector<bool> occ(n + 1);
    vector<int> ans(n);
    map<int, int> rev;
    for (int i = 0; i < n; i++) {
        if (!occ[v[i]]) {
            ans[i] = v[i];
            occ[v[i]] = true;
            rev[v[i]] = i;
        }
    }

    int cur = 1;
    for (int i = 0; i < n; i++) {
        if (ans[i]) {
            continue;
        }

        while (occ[cur]) {
            cur++;
        }

        if (i + 1 != cur) {
            ans[i] = cur;
            rev[cur] = i;
        } else {
            ans[rev[v[i]]] = cur;
            rev[cur] = rev[v[i]];
            ans[i] = v[i];
            rev[v[i]] = i;
        }
        occ[cur] = true;
    }

    for (int a : ans) {
        cout << a << " ";
    }
    cout << "\n";
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
