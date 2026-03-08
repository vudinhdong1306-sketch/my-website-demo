#include <bits/stdc++.h>
using namespace std;

int countPS(string& s){
    int n = s.length();
    int res = 0;

    vector<vector<bool>> dp(n, vector<bool>(n, false));// Tạo mảng QHD và đặt ban đầu deeuf là false

    // Xâu có độ dài 1 luôn là xâu đối xứng
    for(int i = 0; i < n; i++){
        dp[i][i] = true;
     // Đếm luôn xâu độ dài 1
    }

    // Xâu có độ dài 2 là đối xứng nếu 2 phần tử giống nhau
    for(int i = 0; i < n - 1; i++){
        if(s[i] == s[i + 1]){
            dp[i][i + 1] = true;
            res++;
        }
    }

    // Xử lý xâu có độ dài lớn hơn 2
    for(int gap = 2; gap < n; gap++){
        for(int i = 0; i < n - gap; i++){
            int j = i + gap;
            if(s[i] == s[j] && dp[i + 1][j - 1]){
                dp[i][j] = true;
                res++;
            }
        }
    }

    return res;
}

int main(){
    string s;
    cin >> s;
    cout << countPS(s) << endl;
    return 0;
}
