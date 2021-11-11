#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int rand(int a, int b)
{
    return a + rand() % (b - a + 1);
}

int main(int argc, char* argv[])
{
    int seed = atoi(argv[1]);
    srand(seed);

    for (int i = 0; i < 20; i++) {
        int r = rand(0, 9);
        cout << r;
    }
}
