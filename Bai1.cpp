// Bài toán bậc thang
/*Bờm chơi trò chơi điện tử Lucky Luke đến màn phải điều khiển Lucky leo lên một cầu thang gồm N
 bậc.Các bậc thang được đánh số từ 1 đến N
 từ dưới lên trên. Lucky có thể đi lên một bậc thang, hoặc nhảy một bước lên hai bậc thang. 
 Tuy nhiên một số bậc thang đã bị thủng do cũ kỹ và Lucky không thể bước chân lên được. 
 Biết ban đầu, Lucky đứng ở bậc thang số 1 (bậc thang số 1 không bao giờ bị thủng).

Chơi đến đây, Bờm chợt nảy ra câu hỏi: có bao nhiêu cách để Lucky leo hết được cầu thang? (nghĩa là leo đến bậc thang thứ 
). Bờm muốn nhờ bạn trả lời câu hỏi này.*/
#include<bits/stdc++.h>
using namespace std;
const int MOD = 14062008;
int main(){
    int N, K;
    cin >> N >> K;
    vector<bool>broken(N+1,false);
    for(int i=0;i<K;i++){
        int x;
        cin >> x;
        broken[x]=true;
    }
    vector<int> dp(N+1,0);
    dp[1]=1;
    for(int i=2;i<=N;i++){
        if(!broken[i]){
            dp[i]=(dp[i-1]+dp[i-2]) % MOD;
        }
    }
    cout<< dp[N]%MOD << "\n";
    return 0;
}