#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(int t)
{
    int n; cin >> n;
    int canvas[n][n];
    int zeroX = -1, zeroY = -1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            cin >> canvas[i][j];
            if (canvas[i][j] == 0) {
                zeroX = i;
                zeroY = j;
            }
        }

    int twos[n][n], fives[n][n];
    int pathTwos[n][n], pathFives[n][n];
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
        int num = canvas[i][j];
        twos[i][j] = fives[i][j] = 0;
        while (num > 0 && num % 2 == 0) {
            twos[i][j]++;
            num >>= 1;
        }
        num = canvas[i][j];
        while (num > 0 && num % 5 == 0) {
            fives[i][j]++;
            num /= 5;
        }
    }


    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
        pathTwos[i][j] = twos[i][j];
        pathFives[i][j] = fives[i][j];
        if (i > 0 && j > 0) {
            pathTwos[i][j] += min(pathTwos[i-1][j], pathTwos[i][j-1]);
            pathFives[i][j] += min(pathFives[i-1][j], pathFives[i][j-1]);
        } else if (i > 0) {
            pathTwos[i][j] += pathTwos[i-1][j];
            pathFives[i][j] += pathFives[i-1][j];
        } else if (j > 0) {
            pathTwos[i][j] += pathTwos[i][j-1];
            pathFives[i][j] += pathFives[i][j-1];
        }
    }

    string trace = "";
    if (pathTwos[n-1][n-1] < pathFives[n-1][n-1]) {
        int x = n - 1, y = n - 1;
        while (x > 0 || y > 0) {
            if (x > 0 && pathTwos[x][y] - twos[x][y] == pathTwos[x-1][y]) {
                trace += "D";
                x--;
            } else {
                trace += "R";
                y--;
            }
        }
    } else {
        int x = n - 1, y = n - 1;
        while (x > 0 || y > 0) {
            if (x > 0 && pathFives[x][y] - fives[x][y] == pathFives[x-1][y]) {
                trace += "D";
                x--;
            } else {
                trace += "R";
                y--;
            }
        }
    }

    int len = min(pathTwos[n-1][n-1], pathFives[n-1][n-1]);
    if (zeroX != -1 && len > 1) {
        cout << 1 << "\n";
        for (int i = 0; i < zeroX; i++) cout << "D";
        for (int i = 0; i < n - 1; i++) cout << "R";
        for (int i = 0; i < n - zeroX - 1; i++) cout << "D";
        cout << "\n";
    } else {
        reverse(trace.begin(), trace.end());
        cout << len << "\n";
        cout << trace << "\n";
    }
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
    // freopen("", "r", stdin);
	int T = 1;
	for (int t = 1; t <= T; t++) solve(t);
}

