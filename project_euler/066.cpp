#include <bits/stdc++.h>
using namespace std;

bool is_square(long long n)
{
    long long rt = sqrt(n);
    return rt * rt == n;
}

long long chakravala(long long n)
{
    long long a, b, k;
    a = n;
    b = 1;
    k = a * a - n;

    while (k != 1) {
        long long a2, b2, k2, m;
        m = 0;
        while ((a + b * m) % k) {
            m++;
        }

        long long m2 = m + abs(k);
        while (abs(m2 * m2 - n) < abs(m * m - n)) {
            m = m2;
            m2 += abs(k);
        }

        //printf("%d^2 - %d * %d^2 = %d\n", a, n, b, k);

        a2 = (a * m + n * b) / abs(k);
        b2 = (a + b * m) / abs(k);
        k2 = (m * m - n) / k;

        a = a2, b = b2, k = k2;
    }

    return a;
}

int main()
{
    const int N = 1000;
    long long ans = -1;
    for (int d = 278; d <= N; d++) {
        if (is_square(d)) {
            continue;
        }

        long long x = chakravala(d);
        cout << d << " " << x << "\n";
        ans = max(ans, x);
    }
    cout << ans << "\n";

    return 0;
}
