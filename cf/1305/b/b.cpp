#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(int t)
{
    string s; cin >> s;

    int fst = s.find_first_of('(');
    if (fst == -1 || s.find(')', fst) == -1) {
        cout << 0 << "\n";
        return;
    }

    vector<int> removed;
    int i = 0, j = s.size() - 1;
    while (i < j) {
        if (s[i] == ')') i++;
        else if (s[j] == '(') j--;
        else {
            removed.push_back(i);
            removed.push_back(j);
            i++;
            j--;
        }
    }


    sort(removed.begin(), removed.end());
    cout << 1 << "\n";
    cout << removed.size() << "\n";
    for (int a : removed) cout << a + 1 << " ";
    cout << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
    // freopen("", "r", stdin);
	int T = 1;
	for (int t = 1; t <= T; t++) solve(t);
}

