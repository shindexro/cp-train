#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool sufOK(vector<int> deck)
{
    int n = deck.size();
    for (int i = n-1; i >= 0; i--)
    {
        if (deck[i] == 1)
            return true;
        if (i == 0 || deck[i] != deck[i-1] + 1)
            return false;
    }
    assert(false);
    return false;
}

void solve(int _t)
{
    int n; cin >> n;
    set<int> hand;
    vector<int> deck(n);
    for (int i = 0; i < n; i++)
    {
        int a; cin >> a;
        hand.insert(a);
    }
    for (int i = 0; i < n; i++)
        cin >> deck[i];

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (deck[i])
            ans = max(ans, i - deck[i] + 2);
    }
    ans += n;

    if (sufOK(deck))
    {
        int start = 0, cur = deck[n-1];
        while (cur < n)
        {
            if (hand.find(cur + 1) != hand.end())
            {
                hand.erase(cur + 1);
                hand.insert(deck[start]);
                start++;
            }
            else
                break;
            cur++;
        }
        if (cur == n)
        {
            cout << start << "\n";
            return;
        }
    }

    cout << ans << "\n";

}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T = 1;
	for (int t = 1; t <= T; t++) solve(t);
}
