// Lat gach 2*1 va 1*2
#include <bits/stdc++.h>
using namespace std;

int main(){
    int T; cin >> T;
    vector<int> N(T);
    for(int i=0;i<T;i++) cin >> N[i];

    int Nmax = *max_element(N.begin(), N.end());
    vector<long long> dp(Nmax+1,0);
    dp[0]=1;
    dp[1]=1;
    for(int i=2;i<=Nmax;i++){
        dp[i] = dp[i-1] + dp[i-2];
    }

    for(int x : N) cout << dp[x] << "\n";
}
