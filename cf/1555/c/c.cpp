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

void solve(int tc)
{
    int m;
    cin >> m;
    vector<vector<int>> v(2, vector<int>(m));
    for (int& i : v[0])
        cin >> i;
    for (int& i : v[1])
        cin >> i;

    int sum1 = accumulate(all(v[0]), 0);
    int sum2 = accumulate(all(v[1]), 0);

    vector<vector<int>> sv(2, vector<int>(m));
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < m; j++) {
            if (!j) {
                sv[i][j] = v[i][j];
            } else {
                sv[i][j] = sv[i][j - 1] + v[i][j];
            }
        }
    }

    vector<int> opt;
    for (int i = 0; i < m; i++) {
        opt.push_back(max(sum1 - sv[0][i],
            (i - 1 >= 0) ? sv[1][i - 1] : 0));
    }

    cout << *min_element(all(opt)) << "\n";
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
