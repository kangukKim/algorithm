//범위 값 항상 염두에 두기

#include<iostream>
using namespace std;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int N;
    long arr[90];
    
    cin >> N;
    arr[0] = arr[1] = 1;
    for(int i = 2; i < N; i++) {
        arr[i] = arr[i-1] + arr[i-2];
    }
    
    cout << arr[N-1];
    
    return 0;
}
