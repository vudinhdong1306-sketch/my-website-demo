#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin>>n;
    const long long INF=-1e18;
    long long pos=INF, neg=INF;
   
    for(int i=0;i<n;i++){
        // pos là giá trị lớn nhất nếu phần tử cuối được cộng
        // negg là giá trị lớn nhâts nếu phần tử cuối bị trừ
        long long x; cin>>x;
        long long new_pos=pos, new_neg=neg;
        new_pos=max(new_pos,x);
        
        if(neg!=INF) new_pos=max(new_pos, neg+x);
        if(pos!=INF) new_neg=max(new_neg,pos-x);
        pos=new_pos;
        neg=new_neg;
    }
    cout<< pos<<"\n";
    return 0;
}
