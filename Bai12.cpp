#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T, N;
    cin >> T;
    while (T--) {
        cin >> N;
        vector<int> dp(N+1, 0); // dp[s] = số cách đạt tổng s
        dp[0] = 1; // dãy rỗng

        for (int s = 0; s <= N; s++) {
            if (!dp[s]) continue;
            for (int nxt = s+1; nxt <= N-s; nxt++) {
                dp[s+nxt] = (dp[s+nxt] + dp[s]) % MOD;
            }
        }

        int ans = 0;
        for (int s = 1; s <= N; s++) ans = (ans + dp[s]) % MOD;
        cout << ans << "\n";
    }
}
