#include<iostream>
using namespace std;

int dp[101][100001]; // i번째 물건까지 사용하여 k 용량의 가방에 물건 채울때까지 최대 가치
int W[101]; //W - i 번째 물건의 무게
int V[101]; //V - i 번째 물건의 가치


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int N, K;
    cin >> N >> K;
    
    for(int i = 1; i <= N; i++) {
        cin >> W[i] >> V[i];
    }
    
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= K; j++) {
            dp[i][j] = dp[i-1][j];
            if(j-W[i] >= 0 ) {
                dp[i][j] = max(dp[i][j], dp[i-1][j-W[i]] + V[i]);
            }
        }
    }
    cout << dp[N][K];
    
    return 0;
}
