#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct node {
    char c;
    node* l;
    node* r;
    node(char _c, node* _l, node* _r): c(_c), l(_l), r(_r) {};
};

void solve(int t)
{
    string s; cin >> s;

    vector<bool> used(26);
    node *cur = new node(s[0], 0, 0);
    used[s[0] - 'a'] = true;

    for (int i = 1; i < s.size(); i++) {
        char c = s[i];
        if (used[c - 'a']) {
            if (cur->l && cur->l->c == c) cur = cur->l;
            else if (cur-> r && cur->r->c == c) cur = cur->r;
            else {
                cout << "NO\n";
                return;
            }
        } else {
            if (!cur->l) {
                node *n = new node(c, 0, cur);
                cur->l = n;
                cur = n;
                used[c - 'a'] = true;
            } else if (!cur->r) {
                node *n = new node(c, cur, 0);
                cur->r = n;
                cur = n;
                used[c - 'a'] = true;
            } else {
                cout << "NO\n";
                return;
            }
        }
    }

    cout << "YES\n";
    while (cur->l) cur = cur->l;
    while (cur) {
        cout << cur->c;
        cur = cur->r;
    }
    for (int i = 0; i < 26; i++) if (!used[i]) cout << (char)('a' + i);
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

