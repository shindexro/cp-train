#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll fst = 1, snd = 2;
    ll sum = 0;
    while (fst < 4000000) {
        if (fst % 2 == 0) {
            sum += fst;
        }

        ll tmp = fst;
        fst = snd;
        snd += tmp;
    }
    cout << sum << "\n";
    return 0;
}
