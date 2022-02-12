#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<set<int>> combinations;

void generate_combinations(int n, set<int>& comb, int cur, int max_val)
{
    if (comb.size() == n) {
        combinations.push_back(set<int>(comb));
        return;
    }
    if (cur > max_val) {
        return;
    }

    comb.insert(cur);
    generate_combinations(n, comb, cur + 1, 9);
    comb.erase(cur);
    generate_combinations(n, comb, cur + 1, 9);
}

bool can_show_digit(set<int>& nums, int digit)
{
    if (digit == 6 || digit == 9) {
        return nums.find(6) != nums.end() || nums.find(9) != nums.end();
    }
    return nums.find(digit) != nums.end();
}

bool can_form_squares(int i, int j)
{
    vector<pair<int, int>> squares = { { 0, 1 }, { 0, 4 }, { 0, 9 }, { 1, 6 }, { 2, 5 }, { 3, 6 }, { 4, 9 }, { 6, 4 }, { 8, 1 } };

    auto& x = combinations[i];
    auto& y = combinations[j];
    for (auto [a, b] : squares) {
        if (!((can_show_digit(x, a) && can_show_digit(y, b)) || (can_show_digit(x, b) && can_show_digit(y, a)))) {
            return false;
        }
    }

    return true;
}

void print_set(set<int>& nums)
{
    for (auto n : nums) {
        cout << n << " ";
    }
    cout << "\n";
}

int main()
{
    set<int> tmp;
    generate_combinations(6, tmp, 0, 9);

    int ans = 0;
    for (int i = 0; i < combinations.size(); i++) {
        for (int j = i; j < combinations.size(); j++) {
            if (can_form_squares(i, j)) {
                ans++;
            }
        }
    }
    cout << ans << "\n";

    return 0;
}
