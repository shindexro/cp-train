#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int ans = 1;
    for (int i = 1; i <= 20; i++) {
        ans = lcm(ans, i);
    }

    cout << ans << "\n";

    return 0;
}
