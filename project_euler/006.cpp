#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int sum_of_squares = 0;
    int square_of_sum = (1 + 100) * 100 / 2;
    square_of_sum *= square_of_sum;
    for (int i = 1; i <= 100; i++) {
        sum_of_squares += i * i;
    }

    cout << square_of_sum - sum_of_squares << "\n";

    return 0;
}
