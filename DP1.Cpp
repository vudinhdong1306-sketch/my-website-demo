#include<bits/stdc++.h>

using namespace std;

int main(){

    int N;
    cin >> N;
    vector<int> H(N);// Mảng các giá trị độ cao
    for(int i=0;i<N;i++){
        cin >> H[i];
    }
    vector<int>dp(N,0);
    dp[0]=0;// trường hợp cơ sở
    for(int i=1;i<N;i++){
        dp[i]=dp[i-1]+abs(H[i]-H[i-1]);
        if(i>1){
            dp[i]=min(dp[i],dp[i-2]+abs(H[i]-H[i-2]));
        }
    }
    cout << dp[N-1]<<endl;
    return 0;
}