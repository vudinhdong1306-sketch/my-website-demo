#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const long long INF = 1e18;

int main() {
    int N, W;
    cin >> N >> W;
    
    vector<int> w(N), v(N);
    for (int i = 0; i < N; ++i) {
        cin >> w[i] >> v[i];
    }
    
    // Tính tổng giá trị tối đa có thể đạt được
    int max_total_value = 0;
    for (int i = 0; i < N; ++i) {
        max_total_value += v[i];
    }
    
    // Khởi tạo mảng DP: dp[value] = khối lượng nhỏ nhất để đạt được 'value'
    vector<long long> dp(max_total_value + 1, INF);
    dp[0] = 0; // Giá trị 0 cần khối lượng 0
    
    for (int i = 0; i < N; ++i) {
        for (int j = max_total_value; j >= v[i]; --j) {
            if (dp[j - v[i]] != INF) {
                dp[j] = min(dp[j], dp[j - v[i]] + w[i]);
            }
        }
    }
    
    // Tìm giá trị lớn nhất mà dp[value] <= W
    int result = 0;
    for (int j = max_total_value; j >= 0; --j) {
        if (dp[j] <= W) {
            result = j;
            break;
        }
    }
    
    cout << result << endl;
    
    return 0;
}