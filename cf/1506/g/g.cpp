#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD ((int)(1e9 + 7))


void solve(int _t)
{
    string s; cin >> s;
    int n = s.size();
    
    unordered_map<char,int> lastPos;
    unordered_set<int> unused;
    for(int i = 0; i < n; i++)
    {
        lastPos[s[i]] = i;
        unused.insert(s[i]);
    }

    int from = 0;
    for(int i = 0; i < n; i++)
    {
        char c = s[i];
        if(lastPos[c] == i && unused.find(c) != unused.end())
        {
            char mx = 0;
            int mxIdx = -1;
            while(mx != c)
            {
                mx = 0;
                for(int j = from; j <= i; j++)
                {
                    if(s[j] > mx && unused.find(s[j]) != unused.end())
                    {
                        mx = s[j];
                        mxIdx = j;
                    }
                }
                cout << mx;
                unused.erase(mx);
                from = mxIdx + 1;
            }
        }
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
