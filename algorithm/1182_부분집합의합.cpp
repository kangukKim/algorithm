#include<iostream>
using namespace std;

int N, S;

int arr[20];

int cnt, sum;


void solution(int idx) {
    for(int i = idx; i < N; i++) {
        sum += arr[i];
        if (sum == S) {
            cnt++;
        }
        if(i+1 < N) {
            solution(i+1);
        }
        sum -= arr[i];
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    cin >> N >> S;
    cnt = sum = 0;
    for (int i = 0; i < N ; i++) {
        cin >> arr[i];
    }
    
    solution(0);
    
    cout << cnt;
    
    return 0;
}
