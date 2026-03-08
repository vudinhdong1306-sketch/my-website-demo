// LIS (bản đơn giản O(n^2))
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; 
    cin >> n;
    vector<int> arr(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    // Quy hoạch đổng dãy con tăng dài nhất tại vị trí i
    vector<int> dp(n+1, 1);  // mỗi phần tử ít nhất là 1
    int maxLen = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i; j++) { // chỉ xét phần tử trước i
            if (arr[j] < arr[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        maxLen = max(maxLen, dp[i]);
    }

    cout << maxLen << endl;
}
