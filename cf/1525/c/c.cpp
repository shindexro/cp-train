#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(int _t)
{
    int n, m; cin >> n >> m;
    vector<int> robot(n), dir(n);
    for (int i = 0; i < n; i++)
        cin >> robot[i];
    for (int i = 0; i < n; i++)
        cin >> dir[i];

    vector<pair<int,int>> robotOdd, robotEven;
    for (int i = 0; i < n; i++)
    {
        pair<int,int> p = {robot[i], i};
        if (i % 2 == 1)
            robotOdd.push_back(p);
        else
            robotEven.push_back(p);
    }
    sort(robotOdd.begin(), robotOdd.end());
    sort(robotEven.begin(), robotEven.end());




}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) solve(t);
}
