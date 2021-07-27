#include<iostream>
using namespace std;
int arr[1001][1001];
int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int N, K;
    
    cin >> N >> K;
    
    arr[0][1] = 1;
    arr[1][1] = 1;
    arr[1][2] = 1;
    
    for(int i = 2; i <= N; i++) {
        arr[i][1] = 1;
        for(int j = 2; j <= i; j++) {
            arr[i][j] = (arr[i-1][j-1] + arr[i-1][j]) % 10007;
        }
        arr[i][i+1] = 1;
    }
    
    cout << arr[N][K+1];
    
    return 0;
    
}
