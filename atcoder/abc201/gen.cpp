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
    int h = rand(1, 2);
    int w = rand(1, 3);

    cout << h << " " << w << "\n";
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (rand(0, 1))
                cout << '-';
            else
                cout << '+';
        }
        cout << "\n";
    }
}

