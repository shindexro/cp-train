#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll digitSum(ll num)
{
    ll sum = 0;
    while (num) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

ll gcd(ll a, ll b)
{
    if (b == 0) return a;
    return gcd(b, a % b);
}

void solve(int t)
{
    ll n; cin >> n;

    while (gcd(n, digitSum(n)) == 1) n++;
    cout << n << "\n";    
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
    // freopen("", "r", stdin);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) solve(t);
}

