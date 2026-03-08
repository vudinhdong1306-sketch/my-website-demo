#include <bits/stdc++.h>
using namespace std;

const int NEG = -1e9; // âm vô cùng để biểu diễn trạng thái không hợp lệ

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    vector<vector<int>> F(n+1, vector<int>(k, NEG));
    F[0][0] = 0;

    for (int i = 1; i <= n; i++) {
        for (int r = 0; r < k; r++) {
            // không chọn arr[i]
            F[i][r] = max(F[i][r], F[i-1][r]);
            // chọn arr[i]
            if (F[i-1][r] != NEG) {
                int nxt = (r + arr[i]) % k;
                F[i][nxt] = max(F[i][nxt], F[i-1][r] + 1);
            }
        }
    }

    cout << F[n][0] << "\n";
}
