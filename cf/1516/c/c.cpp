#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD ((int)(1e9 + 7))

bool good(vector<int> arr, int sum)
{
    if (sum % 2 == 1)
        return true;
    
    int target = sum / 2;
    int n = arr.size();
    bool part[target + 1][n + 1];
    for (int t = 0; t <= target; t++)
    {
        for (int i = 0; i <= n; i++)
        {
            part[t][i] = false;
            if (t == 0)
            {
                part[t][i] = true;
                continue;
            }
            else if (i == 0)
                continue;

            if (arr[i-1] <= t)
                part[t][i] = part[t - arr[i-1]][i - 1] | part[t][i-1];
            else
                part[t][i] = part[t][i-1];
        }
    }
    
    return !part[target][n];
}


void solve(int _t)
{
    int n; cin >> n;
    vector<int> arr(n);
    int sum = 0, oddIdx = -1;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
        if (arr[i] % 2 == 1)
            oddIdx = i;
    }

    if (good(arr, sum))
    {
        cout << "0\n";
        return;
    }

    while (oddIdx == -1)
    {
        for (int i = 0; i < n; i++)
        {
            arr[i] /= 2;
            if (arr[i] % 2 == 1)
                oddIdx = i;
        }
    }
    cout << "1\n";
    cout << oddIdx + 1 << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
    // freopen("", "r", stdin);
	int T = 1;
	for (int t = 1; t <= T; t++) solve(t);
}
