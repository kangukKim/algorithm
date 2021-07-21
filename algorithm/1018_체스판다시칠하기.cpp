#include<iostream>
using namespace std;

int N, M;

char tmp[8][8];

char arr[51][51];

int minCount = 1000;

void makeTmpArray(int startRow, int startColumn) {
    int row = startRow;
    int col = startColumn;
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            tmp[i][j] = arr[row][col];
            col++;
        }
        row++;
        col = startColumn;
    }
    //(0,0) is White
}

void solution() {
    int Bcnt = 0;
    int Wcnt = 0;
    // (0,0) is Black
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            if((i + j) % 2 == 0) {
                if(tmp[i][j] == 'W') {
                    Bcnt++;
                }            }
            
            if((i + j) % 2 == 1) {
                if(tmp[i][j] == 'B') {
                    Bcnt++;
                }
            }
        }
    }
    //(0,0) is White
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            if((i + j) % 2 == 0) {
                if(tmp[i][j] == 'B') {
                    Wcnt++;
                }            }
            
            if((i + j) % 2 == 1) {
                if(tmp[i][j] == 'W') {
                    Wcnt++;
                }
            }
        }
    }
    
    if(Bcnt < minCount) {
        minCount = Bcnt;
    }
    if(Wcnt < minCount) {
        minCount = Wcnt;
    }
}
int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    
    cin >> N >> M;
    
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            cin >> arr[i][j];
        }
    }
    
    for(int i = 1; i <= N - 7; i++) {
        for(int j = 1; j <= M - 7; j++) {
            makeTmpArray(i, j);
            solution();
        }
    }
    
    cout << minCount;
    return 0;
}
