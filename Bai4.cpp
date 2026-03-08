#include<bits/stdc++.h>
using namespace std;
int min3(int a,int b,int c){
   int min_value=min(a,b);
   return min(min_value,c);
}
int main(){
   int N;
   cin>>N;
   vector<int>t(N+1);
   vector<int>r(N);
   for(int i=1;i<=N;i++){
      cin>> t[i];
   }
   for(int i=1;i<N;i++){
      cin>>r[i];
   }
   vector<int>dp(N+1);
   dp[0]=0;
   dp[1]=t[1];
   vector<bool>Dau(N+1,true);
   for(int i=2;i<=N;i++){
      dp[i]=min(dp[i-1]+t[i],dp[i-2]+r[i-1]);
   }
   cout<<dp[N]<<"\n";
}
