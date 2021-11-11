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
    vector<int> p(n + 1);
    set<int> remain;
    for (int i = 1; i <= n; i++) {
        remain.insert(i);
    }

    int mid = n / 2;

    while (remain.size() > 1) {
        auto it = remain.end();
        it--;
        int a = *it;
        it--;
        int b = *it;

        cout << "? ";
        for (int i = 1; i <= mid; i++) {
            cout << a << " ";
        }
        for (int i = mid + 1; i <= n; i++) {
            cout << b << " ";
        }
        cout << "\n";

        int res;
        cin >> res;
        if (res) {
            if (res <= mid) {
                p[res] = res - a;
            } else {
                p[res] = res - b;
            }
            remain.erase(p[res]);
            continue;
        }

        cout << "? ";
        for (int i = 1; i <= mid; i++) {
            cout << b << " ";
        }
        for (int i = mid + 1; i <= n; i++) {
            cout << a << " ";
        }
        cout << "\n";

        cin >> res;
        if (res) {
            if (res <= mid) {
                p[res] = res - b;
            } else {
                p[res] = res - a;
            }
            remain.erase(p[res]);
            continue;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (!p[i]) {
            p[i] = *remain.begin();
            break;
        }
    }
    cout << "! ";
    for (int i = 1; i <= n; i++) {
        cout << p[i] << " ";
    }
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    // cin.tie(nullptr);
    int T = 1;
    for (int t = 1; t <= T; t++)
        solve(t);
}
