#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, W;
    cin >> N >> W;
    
    vector<int> w(N), v(N);
    for (int i = 0; i < N; ++i) {
        cin >> w[i] >> v[i];
    }
    // Tính tổng giá trị tối đa

    vector<long long> dp(W + 1, 0);
    
    for (int i = 0; i < N; ++i) {
        for (int j = W; j >= w[i]; --j) { // Với mỗi đồ vật sẽ cập nhật từ W->w[i] để đảm bảo mỗi đồ vật chỉ được chọn 1 lần
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
           }
    }
    
    cout << dp[W] << endl;
    
    return 0;
}