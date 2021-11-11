#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(int t)
{
    int d, sumTime;
    cin >> d >> sumTime;
    vector<int> minTimes(d), maxTimes(d);
    int minTotal = 0, maxTotal = 0;
    for (int i = 0; i < d; i++) {
        cin >> minTimes[i] >> maxTimes[i];
        minTotal += minTimes[i];
        maxTotal += maxTimes[i];
    }

    if (sumTime < minTotal || sumTime > maxTotal) {
        cout << "NO";
    } else {
        cout << "YES\n";
        sumTime -= minTotal;
        for (int i = 0; i < d; i++) {
            int spentExtra = min(maxTimes[i] - minTimes[i], sumTime);
            sumTime -= spentExtra;
            cout << minTimes[i] + spentExtra << " ";
        }
    }
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
    // freopen("", "r", stdin);
	int T = 1;
	for (int t = 1; t <= T; t++) solve(t);
}

