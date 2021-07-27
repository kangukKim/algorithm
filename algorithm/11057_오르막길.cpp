#include<iostream>
using namespace std;

int arr[10][1001];

int N;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    cin >> N;
    
    for(int i = 0; i < 10 ; i++) {
        arr[i][1] = 1;
    }
    
    for(int i = 2; i <= N ; i++) {
        int sum = 0;
        for(int j = 0; j < 10; j++) {
            sum += arr[j][i-1];
            arr[j][i] = sum % 10007;
        }
    }
    int sum = 0;
    for(int i = 0; i < 10 ; i++) {
        sum += arr[i][N];
    }
    
    cout << sum % 10007 ;
    
    return 0;
}
