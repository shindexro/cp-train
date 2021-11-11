#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int rand(int a, int b)
{
    return a + rand() % (b - a + 1);
}

int main(int argc, char* argv[])
{
    int seed, n, k;
    seed = atoi(argv[1]);
    srand(seed);
    n = rand(2, 10);
    k = rand(0, n/2);

    cout << n << "\n";
    vector<int> a(n);
    while (k--)
    {
        int x;
        do
        {
            x = rand(0, n-1);
        } while (a[x]);
        a[x] = 1;
    }
    for (int x : a)
        cout << x << " ";
    cout << "\n";
    return 0;
}

