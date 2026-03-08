/*Bài toán tìm xâu con chung dài nhất:
+có thể có nhiều xâu con chung dài nhất và in ra xâu đầu tiên xuất hiện
+in theo thứ tự từ trái sang phải*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s, t;
    cin >> s >> t;
    int m = s.size(), n = t.size();
    // Khởi tạo mảng QHD
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // Tính bảng dp
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (s[i - 1] == t[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    // Truy vết để in ra xâu con chung dài nhất đầu tiên (ưu tiên j--)
    string res = "";     
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (s[i - 1] == t[j - 1]) {
            res += s[i - 1];
            --i;
            --j;
        // do có 2 hướng đi dp[i-1][j]=dp[i][j-1] nên ưu tiên j-- trước để in ra xâu từ trái sang phải
        } else if (dp[i][j - 1] >= dp[i - 1][j]) {
            --j;  // Ưu tiên sang trái để lấy xâu đầu tiên
        } else {
            --i;
        }
    }
    // sau khi truy vết tất cả các phần tử ta đảo ngược lại các phần tử 
    reverse(res.begin(), res.end());
    cout << res << endl;

    return 0;
}
