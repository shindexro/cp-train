#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD ((int)(1e9 + 7))

void setDepth(int *perm, int *depth, int from, int to)
{
    if (from >= to) return;

    int maxIndex = from;
    for (int i = from; i < to; i++)
    {
        if (perm[i] > perm[maxIndex])
        {
            maxIndex = i;
        }
    }

    for (int i = from; i < maxIndex; i++)
        depth[i]++;
    for (int i = maxIndex + 1; i < to; i++)
        depth[i]++;

    setDepth(perm, depth, from, maxIndex);
    setDepth(perm, depth, maxIndex + 1, to);
}


void solve(int _t)
{
    int n; cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];

    int depth[n];
    for (int i = 0; i < n; i++) depth[i] = 0;
    setDepth(arr, depth, 0, n);
    for (int i = 0; i < n; i++)
    {
        cout << depth[i] << " ";
    }
    cout << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
    // freopen("", "r", stdin);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) solve(t);
}
