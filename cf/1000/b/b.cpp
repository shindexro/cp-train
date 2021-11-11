#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(int t)
{
    int n, M; cin >> n >> M;
    vector<int> A;
    A.push_back(0);
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        A.push_back(a);
    }
    if (A.size() % 2 == 1) A.push_back(M);

    int lit = 0;
    for (int i = 1; i < A.size(); i += 2) {
        lit += A[i] - A[i - 1];
    }

    int ans = lit;


}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
    // freopen("", "r", stdin);
	int T = 1;
	for (int t = 1; t <= T; t++) solve(t);
}

