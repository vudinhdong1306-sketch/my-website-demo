// Lat gach 3*n
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<long long> results;
    int x;
    while (cin >> x && x != -1) {
        if (x % 2 == 1) {
            results.push_back(0);
            continue;
        }
        vector<long long> dp(x + 1, 0);
        dp[0] = 1;
        if (x >= 2) dp[2] = 3;
        for (int i = 4; i <= x; i += 2) {
            dp[i] = 4 * dp[i - 2] - dp[i - 4];
        }
        results.push_back(dp[x]);
    }

    for (auto v : results) cout << v << "\n";
    return 0;
}
