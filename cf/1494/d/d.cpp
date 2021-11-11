#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

#define N 505

struct Node {
    int salary;
    vector<Node> children;
};

void solve(int tc)
{
    int n;
    cin >> n;
    int sal[N][N];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> sal[i][j];
        }
    }

    map<int, set<int>> edge;
    map<int, int> sal_to_node, node_to_sal;
    for (int i = 1; i <= n; i++) {
        sal_to_node[sal[i][i]] = i;
        node_to_sal[i] = sal[i][i];
    }

    int nodes = n;
    for (int i = 1; i <= n; i++) {
        vector<int> acs(sal[i] + 1, sal[i] + n + 1);
        sort(acs.begin(), acs.end());

        for (int j = 0; j < n; j++) {
            if (sal_to_node.find(acs[j]) == sal_to_node.end()) {
                nodes++;
                sal_to_node[acs[j]] = nodes;
                node_to_sal[nodes] = acs[j];
            }
        }

        for (int j = 1; j < n; j++) {
            if (acs[j - 1] != acs[j]) {
                edge[acs[j - 1]].insert(acs[j]);
            }
        }
    }
    cout << nodes << "\n";
    for (int i = 1; i <= nodes; i++) {
        cout << node_to_sal[i] << " ";
    }
    cout << "\n";
    cout << sal_to_node[(*(--sal_to_node.end())).first] << "\n";
    for (auto& [s, c] : edge) {
        for (int s2 : c) {
            cout << sal_to_node[s] << " " << sal_to_node[s2] << "\n";
        }
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
