#include<bits/stdc++.h>

using namespace std;

// Cách tiếp cận dệ quy

/*int Fibonacci(int n){
    if(n<=1){
        return n;
    }
    return Fibonacci(n-1)+Fibonacci(n-2);
}
int main(){
    int n;
    cin >> n;
    cout << Fibonacci(n); 
}*/

// Cách tiếp cận ghi nhớ -> tránh các phếp tính trung lặp
/*
int fib(int n, vector<int>& memo){
    if(n<=1){
        return n;
    }
    // check ket qua da co trong bang hay chua
    if(memo[n]!=-1){
        return memo[n];
    }
    memo[n]=fib(n-1,memo)+fib(n-2,memo);
    return memo[n];
}

int  fib(int n){
    vector<int>memo(n+1,-1); // tao mang ghi nho gia tri ban dau la -1
    return fib(n,memo);// goi ham de quy ghi nho
}
int main(){
    int n;
    cin >> n;
    cout<< fib(n) << endl;
    return 0;
}*/

// Cach tiep can bottom-up -> quy hoach dong + de quy
/*
int fib(int n){
    if(n<=1){
        return n;
    }
    vector<int>dp(n+1);// tao mang luu gia tri fibonacci
     // truong hop co so
    dp[0]=0;
    dp[1]=1;
    for(int i=2;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}
int main(){
    int n;
    cin >> n;
    cout << fib(n) << endl;
    return 0;
}*/

// su dung ma tran luy thua
