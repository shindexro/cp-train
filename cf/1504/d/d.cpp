#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(int _t)
{
    int n; cin >> n;
    pair<int,int> red = {0,0}, blue = {0,1};
    for (int t = 0; t < n*n; t++)
    {
        int a; cin >> a;
        // red: 1, blue: 2 and 3
        if ((a == 1 || red.first >= n) && blue.first < n)
        {
            int b = (a != 2) ? 2 : 3;
            cout << b << " " << blue.first+1 << " " << blue.second+1 << "\n";
            blue.second += 2;
            if (blue.second >= n)
            {
                blue.first++;
                blue.second = (blue.second + 1) % 2;
            }
        }
        else
        {
            int b = (a != 1) ? 1 : 3;
            cout << b << " " << red.first+1 << " " << red.second+1 << "\n";
            red.second += 2;
            if (red.second >= n)
            {
                red.first++;
                red.second = (red.second + 1) % 2;
            }
        }
        cout.flush();
    }
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T = 1;
	for (int t = 1; t <= T; t++) solve(t);
}
