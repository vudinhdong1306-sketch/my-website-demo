#include <bits/stdc++.h>
using namespace std;

// Hàm tìm max của 3 số
int max3(int a, int b, int c) {
    int max_value = max(a, b);
    return max(max_value, c);
}

int main() {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> arr(m, vector<int>(n));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    // Khởi tạo dp
    vector<vector<int>> dp(m, vector<int>(n, INT_MIN));

    // Cột đầu tiên
    for (int i = 0; i < m; i++) {
        dp[i][0] = arr[i][0];
    }

    // Duyệt từ cột 2 trở đi
    for (int j = 1; j < n; j++) {
        for (int i = 0; i < m; i++) {
            int from_left   = dp[i][j - 1];
            int from_top    = (i > 0)     ? dp[i - 1][j - 1] : INT_MIN;
            int from_bottom = (i < m - 1) ? dp[i + 1][j - 1] : INT_MIN;
            dp[i][j] = max3(from_left, from_top, from_bottom) + arr[i][j];
        }
    }

    // Kết quả: max ở cột cuối cùng
    int ans = INT_MIN;
    for (int i = 0; i < m; i++) {
        ans = max(ans, dp[i][n - 1]);
    }

    cout << ans << "\n";
    return 0;
}
