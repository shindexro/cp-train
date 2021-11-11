#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 25

ll fact[N];
void prep()
{
    fact[0] = 1;
    for (int i = 1; i < N; i++)
    {
        fact[i] = i * fact[i-1];
    }
}

void solve(int _t)
{
    ll n; cin >> n;
    // burnside's lemma
    ll g = n / 2;
    ll ans = fact[n] / g / g / 2;
    cout << ans << "\n";

}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
    prep();
	int T = 1;
	for (int t = 1; t <= T; t++) solve(t);
}
