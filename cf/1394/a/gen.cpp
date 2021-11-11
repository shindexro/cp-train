#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// integer [a, b], inclusive
int rand(int a, int b)
{
    return a + rand() % (b - a + 1);
}

int main(int argc, char* argv[])
{
    int seed = atoi(argv[1]);
    srand(seed);

    int n = 5;
    cout << n << " "
         << rand(1, n) << " "
         << rand(0, n) << "\n";

    for (int i = 0; i < n; i++) {
        cout << rand(0, n) << " ";
    }
}
