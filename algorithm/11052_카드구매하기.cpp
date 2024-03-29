#include<iostream>
using namespace std;
int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int N;
    int arr[1001];
    int dp[1001];
    cin >> N;
    
    for(int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    
    dp[1] = arr[1];
    
    for(int i = 2; i <= N; i++) {
        dp[i] = arr[i];
        for(int j = 1; j < i; j++) {
            dp[i] = max(dp[i], dp[i-j] + arr[j]);
        }
    }
    
    cout << dp[N];
    
    return 0;
}
