#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(int t)
{
    string s; cin >> s;

    int maxlen = 0;
    int freq = 1;
    unordered_map<int, int> opening;

    int count = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            count++;
            if (opening.find(count) == opening.end()) opening[count] = i;
        } else if (count == 0) {
            opening.clear();
        } else {
            int len = i - opening[count] + 1;
            if (len > maxlen) {
                maxlen = len;
                freq = 1;
            } else if (len == maxlen) {
                freq++;
            }
            opening.erase(count + 1);
            count--;
        }
    }
    cout << maxlen << " " << freq << "\n";

}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
    // freopen("", "r", stdin);
	int T = 1;
	for (int t = 1; t <= T; t++) solve(t);
}

