#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void atob(string s)
{
    int col = 0, row = 0;
    for (char c : s) {
        if ('A' <= c && c <= 'Z')
            col = col * 26 + c - 'A' + 1;
        else
            row = row * 10 + c - '0';
    }
    cout << "R" << row << "C" << col << "\n";
}

void btoa(string s)
{
    int row = 0, col = 0;
    int i;
    for (i = 1; i < s.size() && s[i] != 'C'; i++) {
        row = row * 10 + s[i] - '0';
    }
    i++;
    for (; i < s.size(); i++) {
        col = col * 10 + s[i] - '0';
    }
    string scol = "";
    while (col > 0) {
        col--;
        scol += 'A' + col % 26;
        col /= 26;
    }
    reverse(scol.begin(), scol.end());
    cout << scol << row << "\n";
}

regex re = regex("[A-Z]+[0-9]+");

void solve(int t)
{
    string s; cin >> s;

    if (regex_match(s, re))
        atob(s);
    else
        btoa(s);
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
    // freopen("", "r", stdin);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) solve(t);
}

