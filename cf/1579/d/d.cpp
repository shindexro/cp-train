#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
typedef long long ll;

void solve(int tc)
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int& a : arr)
        cin >> a;

    priority_queue<pair<int, int>> q;
    for (int i = 0; i < n; i++) {
        if (arr[i] > 0) {
            q.push({ arr[i], i });
        }
    }

    int k = 0;
    vector<pair<int, int>> ans;
    while (q.size() >= 2) {
        auto p1 = q.top();
        q.pop();
        auto p2 = q.top();
        q.pop();

        ans.push_back({ p1.second, p2.second });
        if (p1.first > 1)
            q.push({ p1.first - 1, p1.second });
        if (p2.first > 1)
            q.push({ p2.first - 1, p2.second });
        k++;
    }

    cout << k << "\n";
    for (auto& a : ans)
        cout << a.first + 1 << " " << a.second + 1 << "\n";
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
