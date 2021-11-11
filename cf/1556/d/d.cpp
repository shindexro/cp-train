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

int extract(int a, int a_and_b, int a_or_b)
{
    return (~a & ~a_and_b & a_or_b) | (a & a_and_b & a_or_b);
}

void solve(int tc)
{
    int n, k;
    cin >> n >> k;

    vector<int> v;

    int a_and_b, a_and_c, b_and_c, a_or_b, a_or_c, b_or_c;
    cout << "and 1 2\n";
    cin >> a_and_b;
    cout << "and 1 3\n";
    cin >> a_and_c;
    cout << "and 2 3\n";
    cin >> b_and_c;
    cout << "or 1 2\n";
    cin >> a_or_b;
    cout << "or 1 3\n";
    cin >> a_or_c;
    cout << "or 2 3\n";
    cin >> b_or_c;

    int a = (~a_and_b & ~a_and_c & ~b_and_c & a_or_b & a_or_c & ~b_or_c)
        | (~a_and_b & a_and_c & ~b_and_c & a_or_b & a_or_c & b_or_c)
        | (a_and_b & ~a_and_c & ~b_and_c & a_or_b & a_or_c & b_or_c)
        | (a_and_b & a_and_c & b_and_c & a_or_b & a_or_c & b_or_c);

    int b = extract(a, a_and_b, a_or_b);
    int c = extract(a, a_and_c, a_or_c);

    v.push_back(a);
    v.push_back(b);
    v.push_back(c);

    for (int i = 4; i <= n; i++) {
        debug(v);
        int a_and_d, a_or_d;
        cout << "and 1 " << i << "\n";
        cin >> a_and_d;
        cout << "or 1 " << i << "\n";
        cin >> a_or_d;

        int d = extract(a, a_and_d, a_or_d);
        v.push_back(d);
    }

    sort(all(v));
    cout << "finish " << v[k - 1] << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    //cin.tie(nullptr);
    int T = 1;
    for (int t = 1; t <= T; t++)
        solve(t);
}
