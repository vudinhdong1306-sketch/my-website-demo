// Bài toán nhày lò cò
#include<bits/stdc++.h>
using namespace std;
int main(){
    /*Tắt đồng bộ hóa iostream với C I/O để đọc/ghi nhanh hơn; cin.tie(0) tách cin khỏi cout.
     Dùng cho bài có input lớn để tăng tốc.*/
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<long long>a(n);
    for(int i=0;i<n;i++){
        cin >> a[i] ;
    }
    // ánh xạ giá trị-> index
    unordered_map<long long,int>pos;
    for(int i=0;i<n;i++){
        pos[a[i]]=i;
    }
    // đồ thị có hướng
    vector<vector<int>>adj(n);
    // dựng cạnh
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            long long sum=a[i]+a[j];
            if(pos.count(sum)){
                int k=pos[sum];
                adj[i].push_back(k);
                adj[j].push_back(k);
            }
        }
    }
    // dp[u]= đường đi dài nhất kết thúc tại u
    vector<int>dp(n,1);
    int ans=1;
    // sắp xếp theo giá trị a[i] để đảm bảo topo
    vector<int>order(n);
    iota(order.begin(),order.end(),0);
    sort(order.begin(),order.end(), [&](int i,int j){ return a[i]<a[j];});
    for(int u:order){
        for(int v: adj[u]){
            dp[v]=max(dp[v],dp[u]+1);
            ans=max(ans,dp[v]);

        }
    }
    cout<<ans<<"\n";
    return 0;
}