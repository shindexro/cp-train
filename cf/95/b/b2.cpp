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

bool ok(string& s)
{
    int len = s.size();
    for (int i = 0; i < len; i++) {
        char d = (i < len / 2) ? '7' : '4';
        if (s[i] > d)
            return false;
        if (s[i] < d)
            return true;
    }
    return true;
}

bool has_greater(string& s, int idx, char val)
{
    for (int i = idx; i < s.size(); i++) {
        if (s[i] > val)
            return true;
    }
    return false;
}

void build(string& s)
{
    string ans = "";
    int fours = s.size() / 2;
    int sevens = s.size() / 2;

    while (fours--)
        ans += '4';
    while (sevens--)
        ans += '7';

    while (ans.compare(s) < 0) {
        next_permutation(all(ans));
    }
    cout << ans;
}

void solve(int tc)
{
    string s;
    cin >> s;
    int len = s.size();

    if (len & 1) {
        for (int i = 0; i < (len + 1) / 2; i++)
            cout << 4;
        for (int i = 0; i < (len + 1) / 2; i++)
            cout << 7;
    } else if (ok(s)) {
        build(s);
    } else {
        for (int i = 0; i < (len + 2) / 2; i++)
            cout << 4;
        for (int i = 0; i < (len + 2) / 2; i++)
            cout << 7;
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
