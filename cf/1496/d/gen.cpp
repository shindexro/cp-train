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

    int n = 8;
    vector<int> v(n);
    for (int i = 1; i <= n; i++) {
        v[i - 1] = i;
    }
    random_shuffle(v.begin(), v.end());

    cout << n << "\n";
    for (int a : v) {
        cout << a << " ";
    }
}
