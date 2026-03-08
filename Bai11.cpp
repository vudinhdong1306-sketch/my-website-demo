// Dãy con chung không liền kề dài nhất
#include<bits/stdc++.h>
using namespace std;
const int maxN=10001;
int A[maxN]; int B[maxN]; int dp[maxN][maxN];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int m,n; cin>>m>>n;
    for(int i=1;i<=m;i++){
        cin>>A[i];
    }
    for(int i=1;i<=n;i++){
        cin>>B[i];
    }
    // mảng quy hoạch động dp[i][j]= độ dài LCS của A[1..i] và B[1..j];
    for(int i=1;i<=m;i++){
        dp[i][0]=0;
    }
    for(int j=1;j<=n;j++){
        dp[0][j]=0;
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(A[i]==B[j]){
                dp[i][j]=dp[i-2][j-2]+1;
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    cout << dp[m][n]<<"\n";
}