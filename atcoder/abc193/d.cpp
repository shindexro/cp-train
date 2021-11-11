#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int score(string s)
{
    vector<int> freq(10);
    for (char c : s)
        freq[c-'0']++;
    
    int res = 0;
    for (int i = 1; i <= 9; i++)
        res += i * pow(10, freq[i]);
    return res;
}

void solve(int _t)
{
    int k; cin >> k;
    string s, t; cin >> s >> t;
    vector<int> sFreq(10), tFreq(10);
    for (int i = 0; i < 4; i++)
        sFreq[s[i]-'0']++;
    for (int i = 0; i < 4; i++)
        tFreq[t[i]-'0']++;

    double ans = 0;
    for (int i = 1; i <= 9; i++)
    {
        double prob1 = 1.0 * (k-sFreq[i]-tFreq[i]) / (9*k-8);
        prob1 = max(0.0, prob1);
        s[4] = '0' + i;
        for (int j = 1; j <= 9; j++)
        {
            double prob2 = 1.0 * (k-sFreq[j]-tFreq[j]-((i==j)?1:0)) / (9*k-9);
            prob2 = max(0.0, prob2);
            t[4] = '0' + j;
            if (score(s) > score(t))
                ans += prob1 * prob2;
        }
    }
    
    cout << fixed << setprecision(9);
    cout << ans;
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T = 1;
	for (int t = 1; t <= T; t++) solve(t);
}

