#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e15;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<long long> d(N); // d[1..N-1]
    for (int i = 1; i <= N-1; i++) cin >> d[i];

    vector<long long> dp(N+1, INF);
    dp[1] = INF;       // không thể chỉ 1 máy
    dp[2] = d[1];      // nối 1-2

    for (int i = 3; i <= N; i++) {
        dp[i] = min(dp[i-1] + d[i-1], dp[i-2] + d[i-1]);
    }

    cout << dp[N] << "\n";
    return 0;
}
