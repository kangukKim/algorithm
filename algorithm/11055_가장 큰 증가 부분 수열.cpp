#include<iostream>
using namespace std;

int dp[1000];
int arr[1000];
int maxValue;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int N;
    
    cin >> N;
    
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    
    dp[0] = arr[0];
    
    for(int i = 0; i < N; i++) {
        dp[i] = arr[i];
        for(int j = 0; j < i; j++) {
            if (arr[j] < arr[i]) {
                dp[i] = max(dp[i], dp[j] + arr[i]);
            }
        }
        maxValue = max(dp[i], maxValue);
    }
    
    cout << maxValue;
    
    return 0;
}
