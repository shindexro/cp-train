#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    for (int a = 1; a < 1000; a++) {
        for (int b = a + 1; b < 1000; b++) {
            for (int c = b + 1; c < 1000; c++) {
                if (a * a + b * b == c * c && a + b + c == 1000) {
                    cout << a << " " << b << " " << c << "\n";
                    cout << a * b * c << "\n";
                }
            }
        }
    }

    return 0;
}
