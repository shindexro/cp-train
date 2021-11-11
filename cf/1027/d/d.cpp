#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
typedef long long ll;

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

int hare(vector<int>& v, int i, vector<bool>& seen)
{
    int slow = i;
    int fast = i;
    do {
        slow = v[slow];
        fast = v[v[fast]];
        if (seen[fast])
            return -1;
    } while (fast != slow);
    slow = i;
    while (fast != slow) {
        slow = v[slow];
        fast = v[fast];
    }
    return slow;
}

void solve(int tc)
{
    int n;
    cin >> n;
    vector<int> c(n), v(n);
    for (int& i : c)
        cin >> i;
    for (int& i : v) {
        cin >> i;
        i--;
    }

    int ans = 0;
    vector<bool> seen(n);
    for (int i = 0; i < n; i++) {
        if (seen[i])
            continue;
        int cycle = hare(v, i, seen);
        if (cycle == -1) {
            int cur = i;
            while (!seen[cur]) {
                seen[cur] = true;
                cur = v[cur];
            }
            continue;
        }
        int cur = i;
        while (cur != cycle) {
            seen[cur] = true;
            cur = v[cur];
        }
        seen[cur] = true;
        int cost = c[cur];
        cur = v[cur];
        while (cur != cycle) {
            seen[cur] = true;
            cost = min(cost, c[cur]);
            cur = v[cur];
        }
        debug(i, cycle, cost);
        ans += cost;
    }

    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    for (int t = 1; t <= T; t++)
        solve(t);
}
