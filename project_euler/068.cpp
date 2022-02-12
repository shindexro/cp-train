#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string concat_nums(vector<int>& nums)
{
    string s = "";
    for (auto n : nums) {
        s += to_string(n);
    }
    return s;
}

int main()
{
    const int N = 5;
    vector<int> nums;
    for (int i = 1; i <= N * 2; i++) {
        nums.push_back(i);
    }

    string ans = "";
    do {
        int target = -1;
        vector<vector<int>> lines;

        for (int i = 1; i <= N; i++) {
            int a = i;
            int b = (i == N) ? 1 : i + 1;
            int c = N + i;
            int sum = nums[a - 1] + nums[b - 1] + nums[c - 1];
            if (target == -1) {
                target = sum;
            }
            if (sum == target) {
                lines.push_back({ nums[c - 1], nums[a - 1], nums[b - 1] });
            }
        }

        if (lines.size() == N) {
            int idx = 0;
            for (int i = 0; i < N; i++) {
                if (lines[i][0] < lines[idx][0]) {
                    idx = i;
                }
            }

            string s = "";
            for (int i = 0; i < N; i++) {
                s += concat_nums(lines[(idx + i) % N]);
            }

            if (s.compare(ans) > 0) {
                ans = s;
            }
        }
    } while (next_permutation(nums.begin(), nums.end()));

    cout << ans << "\n";

    return 0;
}
