// Đây là bài mở rộng của bài DP1

#include<bits/stdc++.h>

using namespace std;

int main(){
    int N,K;
    cin >> N >> K;
    vector<int>H(N);
    for(int i=0;i<N;i++){
        cin >> H[i];
    }
    vector<int>dp(N,0);
    dp[0]=0;
    for(int i=1;i<N;i++){
        dp[i]=INT_MAX;// khởi tạo dp[i] ban đầu
        for(int j = max(0,i-K);j<i;j++){
            dp[i]=min(dp[i],dp[j]+abs(H[i]-H[j]));
        }

    }
    cout<< dp[N-1]<< endl;
    return 0;

}