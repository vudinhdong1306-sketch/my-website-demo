#include <bits/stdc++.h>
using namespace std;

int maxGold(const vector<int>& a, int L1, int L2) {
    int n = a.size();
    vector<int> dp(n + 1, 0);
    deque<int> dq; // Lưu các chỉ số ứng viên j

    int result = 0;

    for (int i = 1; i <= n; ++i) {
        // Loại bỏ các chỉ số j không còn nằm trong đoạn [i - L2, i - L1]
        while (!dq.empty() && dq.front() < i - L2)
            dq.pop_front();

        // Nếu i - L1 >= 1 thì có thể thêm i - L1 vào deque
        if (i - L1 >= 1) {
            int j = i - L1;
            // Duy trì dq giảm dần theo dp[j]
            while (!dq.empty() && dp[dq.back()] <= dp[j])
                dq.pop_back();
            dq.push_back(j);
        }

        // Tính dp[i]
        if (!dq.empty())
            dp[i] = a[i - 1] + dp[dq.front()];
        else
            dp[i] = a[i - 1];

        result = max(result, dp[i]);
    }

    return result;
}

int main() {
    int n, L1, L2;
    cin >> n >> L1 >> L2;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    cout << maxGold(a, L1, L2) << endl;
    return 0;
}
