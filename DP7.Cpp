    #include <bits/stdc++.h>
    using namespace std;

    const int MAX = 1e5 + 5;

    vector<int> adj[MAX];
    int in_deg[MAX], dp[MAX];

    int main() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int N, M;
        cin >> N >> M;

        // Đọc các cạnh
        for (int i = 0; i < M; ++i) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            in_deg[v]++;
        }

        // Hàng đợi topo
        queue<int> q;

        // Khởi tạo các đỉnh có indegree = 0
        for (int i = 1; i <= N; ++i)
            if (in_deg[i] == 0)
                q.push(i);

        // Topo sort + tính độ dài đường đi
        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v : adj[u]) {
                dp[v] = max(dp[v], dp[u] + 1);
                in_deg[v]--;
                if (in_deg[v] == 0)
                    q.push(v);
            }
        }

        // Kết quả là độ dài lớn nhất trong mảng dp
        cout << *max_element(dp + 1, dp + N + 1) << '\n';

        return 0;
    }
