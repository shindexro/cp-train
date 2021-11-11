#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
typedef long long ll;

void solve(int tc)
{
    string s;
    cin >> s;

    int a = count(all(s), 'A');
    int b = count(all(s), 'B');
    int c = count(all(s), 'C');
    
    if (b == a+c)
        cout << "yes\n";
    else
        cout << "no\n";
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
