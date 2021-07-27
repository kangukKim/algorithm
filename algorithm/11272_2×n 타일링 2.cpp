#include<iostream>
using namespace std;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int N;
    int arr[1000];
    
    cin >> N;
    arr[0] = 1;
    arr[1] = 3;
    for(int i = 2; i < N; i++) {
        arr[i] = (arr[i-1] + arr[i-2] * 2) % 10007;
    }
    
    cout << arr[N-1];
    
    return 0;
}
