// bản code C của bài TSP
#include <stdio.h>
#include <limits.h>

#define MAX 20
#define INF 1000000000

int n;
int cost[MAX][MAX];
int dp[1 << MAX][MAX];

// Hàm TSP: mask là tập các thành phố đã đi qua, pos là thành phố hiện tại
int tsp(int mask, int pos) {
    if (mask == (1 << n) - 1) {
        return cost[pos][0];  // quay về thành phố 0
    }

    if (dp[mask][pos] != -1) {
        return dp[mask][pos];
    }

    int minCost = INF;
    for (int city = 0; city < n; city++) {
        if (!(mask & (1 << city))) {
            int newCost = cost[pos][city] + tsp(mask | (1 << city), city);
            if (newCost < minCost) {
                minCost = newCost;
            }
        }
    }

    dp[mask][pos] = minCost;
    return minCost;
}

int main() {
    printf("Nhập số thành phố (n <= 20): ");
    scanf("%d", &n);

    printf("Nhập ma trận chi phí %d x %d:\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    // Khởi tạo dp với -1
    for (int i = 0; i < (1 << n); i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] = -1;
        }
    }

    int result = tsp(1, 0); // Bắt đầu từ thành phố 0, mask = 1 (chỉ có thành phố 0 đã đi)
    printf("Chi phí hành trình tối ưu: %d\n", result);

    return 0;
}
