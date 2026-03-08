//Phân trang = tối thiểu hóa độ xấu nhất các dòng
#include <bits/stdc++.h>

using namespace std;
const int MAX_INT=1e9;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N,L; cin>>N>>L;
    vector<int>w(N+1);
    for(int i=1;i<= N;i++ ){
        cin>> w[i];
    }
    //prefix sum để tính nhanh tổng độ dài từ i đến j
    vector<int> pref(N+1,0);
    for(int i=1;i<=N;i++) pref[i]=pref[i-1]+w[i];   
    // mảng qhd dp[i] hệ số phạt nhỏ nhất khi phân trang
    vector<int>dp(N+2,0);
    for(int i=N;i>=1;i--){
        int best=MAX_INT;
        for(int j=i;j<=N;j++){
            int sum=pref[j]-pref[i-1];
            if(sum>L){ // vượt quá độ dài của dòng
                break;
            }
            int penalty =L-sum;
            int cost=max(penalty,dp[j+1]);
            best=min(best,cost);
        }
        dp[i]=best;
    }
    cout<<dp[1]<<"\n";
    return 0;
}