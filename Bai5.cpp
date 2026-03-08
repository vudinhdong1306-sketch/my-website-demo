// Ý tưởng: QHD và BST
#include <bits/stdc++.h>
using namespace std;
// Định nghĩa kiểu dữ liệu lưu thời gian
struct Interval {
    int start, end, weight;
};
// Hàm so sánh dùng cho sort , sắp xếp các iterval theo thứ tự tăng dần
bool cmp(const Interval &a, const Interval &b) {
    return a.end < b.end;
}

int main() {
    // Tắt đồng bộ hóa iostream
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<Interval> intervals(n);

    for (int i = 0; i < n; i++) {
        int p, k;
        cin >> p >> k;
        intervals[i] = {p, k, k - p};
    }

    // Sắp xếp theo thời gian kết thúc
    sort(intervals.begin(), intervals.end(), cmp);

    // Lưu danh sách thời gian kết thúc để binary search
    vector<int> ends;
    for (auto &it : intervals) ends.push_back(it.end);

    vector<long long> dp(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        // tìm prev(i)
        int p = intervals[i - 1].start;
        int idx = upper_bound(ends.begin(), ends.end(), p) - ends.begin();
        // idx là số lượng phần tử có end <= p
        dp[i] = max(dp[i - 1], dp[idx] + intervals[i - 1].weight);
    }

    cout << dp[n] << "\n";

    return 0;
}
