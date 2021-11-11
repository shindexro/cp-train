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

class DisjointSet {
private:
    vector<int> label; //label[x] stores the root of x if x is not root, otherwise it stores -(size of x's set).
public:
    DisjointSet() { }
    DisjointSet(int n)
    {
        label.assign(n + 7, -1); //label should contains at least n+1 elements, as x is 1-indexed.
                                 //At first, each node is a seperate set of size 1.
    }
    int find(int x)
    { //find the root of set which contains x.
        if (label[x] < 0)
            return (x); //x is root iff label[x] is negative.
        label[x] = find(label[x]);
        return (label[x]); //find the root of x by recursion.
    }
    bool join(int a, int b)
    { // join the sets which contains a and b. Return false iff a and b are already in the same set.
        int x = find(a);
        int y = find(b);
        if (x == y)
            return (false); //A set contains both a and b.
        if (label[x] > label[y])
            swap(x, y); //label[x]>label[y] means size(x)<size(y).
        //We speed up the disjoint set by joinning the smaller set to the bigger set
        label[x] += label[y];
        label[y] = x; //Update the label of x and y.
        return (true);
    }
    int getSize(int x)
    { //return the size of set which contains x.
        return (-label[find(x)]);
    }
};

#define MAX 100100

void solve(int tc)
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> crews;
    vector<unordered_set<int>> imp(n + 1);

    DisjointSet dsu(MAX);
    for (int i = 0; i < m; i++) {
        int a, b;
        string r;
        cin >> a >> b >> r;

        if (r[0] == 'c') {
            crews.push_back({ a, b });
        } else {
            imp[a].insert(b);
            imp[b].insert(a);
        }
    }

    for (auto [a, b] : crews) {
        dsu.join(a, b);
    }

    int ans = 0;
    vector<bool> seen(n + 1);
    for (int i = 1; i <= n; i++) {
        if (seen[dsu.find(i)])
            continue;

        vector<int> t1, t2;
        queue<pair<int, int>> q;
        q.push({ i, 1 }); // wrong! must consider every node in this set
        seen[i] = true;
        while (q.size()) {
            auto [p, d] = q.front();
            q.pop();
            debug(p, d);
            if (d & 1) {
                t1.push_back(p);
            } else {
                t2.push_back(p);
            }

            for (int p2 : imp[p]) {
                if (seen[p2])
                    continue;
                q.push({ p2, d + 1 });
                seen[p2] = true;
            }
        }
        debug(t1, t2);
        if (!t2.size()) {
            ans += dsu.getSize(t1[0]);
            seen[dsu.find(t1[0])] = true;
            debug(ans, dsu.getSize(t1[0]));
            continue;
        }

        for (int j = 1; j < t1.size(); j++) {
            dsu.join(t1[0], t1[j]);
        }
        for (int j = 1; j < t2.size(); j++) {
            dsu.join(t2[0], t2[j]);
        }

        if (dsu.find(t1[0]) == dsu.find(t2[0])) {
            cout << "-1\n";
            return;
        }
        seen[dsu.find(t1[0])] = seen[dsu.find(t2[0])] = true;
        ans += max(dsu.getSize(t1[0]), dsu.getSize(t2[0]));
        debug(ans, dsu.getSize(t1[0]), dsu.getSize(t2[0]));
    }
    cout << ans << "\n";
    debug(ans);
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
