#include<iostream>
using namespace std;

char arr[51][51];
int N;
int MAX;

void checkRowCloumn(int i1, int j1, int i2, int j2, bool isRow) {
    if (isRow) {
        char prev = arr[i1][1];
        int sum = 1;

        for (int i = 2; i <= N; i++) {
            //행 분석
            if (prev == arr[i1][i]) {
                sum += 1;
            } else {
                prev = arr[i1][i];
                if (sum > MAX) {
                    MAX  = sum;
                }
                sum = 1;
            }
        }
        if (sum > MAX) {
            MAX  = sum;
        }
        
        prev = arr[1][j1];
        sum = 1;
        for (int i = 2; i <= N; i++) {
            //열 분석
            if (prev == arr[i][j1]) {
                sum += 1;
            } else {
                prev = arr[i][j1];
                if (sum > MAX) {
                    MAX  = sum;
                }
                sum = 1;
            }
        }
        if (sum > MAX) {
            MAX  = sum;
        }
        
        prev = arr[1][j2];
        sum = 1;
        for (int i = 2; i <= N; i++) {
            //열 분석
            if (prev == arr[i][j2]) {
                sum += 1;
            } else {
                prev = arr[i][j2];
                if (sum > MAX) {
                    MAX  = sum;
                }
                sum = 1;
            }
        }
        if (sum > MAX) {
            MAX  = sum;
        }
    } else {
        char prev = arr[1][j1];
        int sum = 1;

        for (int i = 2; i <= N; i++) {
            //행 분석
            if (prev == arr[i][j1]) {
                sum += 1;
            } else {
                prev = arr[i][j1];
                if (sum > MAX) {
                    MAX  = sum;
                }
                sum = 1;
            }
        }
        if (sum > MAX) {
            MAX  = sum;
        }
        prev = arr[i1][1];
        sum = 1;
        for (int i = 2; i <= N; i++) {
            //열 분석
            if (prev == arr[i1][i]) {
                sum += 1;
            } else {
                prev = arr[i1][i];
                if (sum > MAX) {
                    MAX  = sum;
                }
                sum = 1;
            }
        }
        if (sum > MAX) {
            MAX  = sum;
        }
        
        prev = arr[i2][1];
        sum = 1;
        for (int i = 2; i <= N; i++) {
            //열 분석
            if (prev == arr[i2][i]) {
                sum += 1;
            } else {
                prev = arr[i2][i];
                if (sum > MAX) {
                    MAX  = sum;
                }
                sum = 1;
            }
        }
        if (sum > MAX) {
            MAX  = sum;
        }
    }
}
int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    cin >> N;
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> arr[i][j];
        }
    }
    
    for (int i = 1; i <= N; i++) {
        //행 분석
        char prev = arr[i][1];
        int sum = 1;
        for (int j = 2; j <= N; j++) {
            if (prev == arr[i][j]) {
                sum += 1;
            } else {
                swap(arr[i][j-1],arr[i][j]);
                checkRowCloumn(i, j-1, i, j, 1);
                swap(arr[i][j-1],arr[i][j]);
                
                prev = arr[i][j];
                if (sum > MAX) {
                    MAX  = sum;
                }
                sum = 1;
            }
        }
        
        if (sum > MAX) {
            MAX  = sum;
        }
        //열 분석
        prev = arr[1][i];
        sum = 1;
        for (int j = 2; j <= N; j++) {
            if (prev == arr[j][i]) {
                sum += 1;
            } else {
                swap(arr[j-1][i],arr[j][i]);
                checkRowCloumn(j-1, i, j, i, 0);
                swap(arr[j-1][i],arr[j][i]);

                prev = arr[j][i];
                if (sum > MAX) {
                    MAX  = sum;
                }
                sum = 1;
            }
        }
        
        if (sum > MAX) {
            MAX  = sum;
        }
    }
    
    cout << MAX;
    
    return 0;
}
