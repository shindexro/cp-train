#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(int t)
{
    int maxlen = 0;
    vector<string> ss;
    string line;
    while (getline(cin, line)) {
        ss.push_back(line);
        maxlen = max(maxlen, (int)line.size());
    }


    bool toLeft = true;
    for (int i = 0; i < maxlen + 2; i++) cout << "*";
    cout << "\n";
    for (string s : ss) {
        cout << "*";
        int spaces = maxlen - s.size();
        int leftSpaces, rightSpaces;
        leftSpaces = rightSpaces = spaces / 2;
        if (spaces % 2 == 1) {
            if (toLeft) rightSpaces++;
            else leftSpaces++;
            toLeft = !toLeft;
        }
        for (int i = 0; i < leftSpaces; i++) cout << " ";
        cout << s;
        for (int i = 0; i < rightSpaces; i++) cout << " ";
        cout << "*";
        cout << "\n";
    }
    for (int i = 0; i < maxlen + 2; i++) cout << "*";
    cout << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
    // freopen("", "r", stdin);
	int T = 1;
	for (int t = 1; t <= T; t++) solve(t);
}

