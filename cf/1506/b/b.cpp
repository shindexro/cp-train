#include <bits/stdc++.h>
using namespace std;
#define umap unordered_map
typedef long long ll;

void solve(int t)
{
	int n, k;
	string s;
	cin >> n >> k >> s;

	int last = n - 1;
	while (s[last] != '*') last--;
    
	int count = 0;
	int i;
	for (i = 0; s[i] != '*'; i++);
	count++;
	
	while (i < last)
	{
		int j;
		for (j = min(last, i + k); s[j] != '*'; j--);
		count++;
		i = j;
	}

    cout << count << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
    // freopen("1506B_case.txt", "r", stdin);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) solve(t);
}