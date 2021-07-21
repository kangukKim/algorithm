//BruteForce 문제
//9명 중 2개만 체크해서 빼면 되므로 이중 포문으로 해결가능

#include<iostream>
#include<algorithm>
using namespace std;

int arr[9];
int sum = 0;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    for(int i = 0; i < 9; i++) {
        cin >> arr[i];
        sum += arr[i];
    }

    for(int i = 0 ; i < 8; i++) {
        for(int j = i+1; j < 9; j++) {
            if(sum - arr[i] - arr[j] == 100) {
                arr[i] = 0;
                arr[j] = 0;
                sort(arr, arr+9);
                for(int z = 2; z < 9; z++) {
                    cout << arr[z] << endl;
                }
                return 0;
            }
        }
    }
}