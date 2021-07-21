//숫자를 정답으로 가정하고 숫자와 스트라이크 볼 숫자가 같지 않은것을 false로 바꿔가면서 가능성이 있는 숫자 체크

#include<iostream>
using namespace std;


bool arr[1000];


void initiazlize() {
    for(int i = 100; i <= 999; i++) {
        arr[i] = true;
        
        string tmp = to_string(i);
        
        if(tmp[0] == tmp[1] || tmp[1] == tmp[2] || tmp[0] == tmp[2]) {
            arr[i] = false;
        }
        
        if(tmp[0] - '0' == 0 || tmp[1] - '0' == 0 || tmp[2] - '0' == 0) {
            arr[i] = false;
        }
    }
}

void solution(int num, int strike, int ball) {

    for(int i = 100; i <= 999; i++) {
        
        if(arr[i] == false) {
            continue;
        }
        
        int tmp_strike = 0;
        int tmp_ball = 0;
        
        string tmp = to_string(i);
        string num_str = to_string(num);
        
        for(int a = 0; a < 3; a++) {
            for(int b = 0; b < 3; b++) {
                if(a == b && num_str[a] == tmp[b]) {
                    tmp_strike++;
                };
                if(a != b && num_str[a] == tmp[b]) {
                    tmp_ball++;
                };
            }
        }
        
        if(tmp_strike != strike || tmp_ball != ball) {
            arr[i] = false;
        }

    }
    
}


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int N;
    cin >> N;
    
    initiazlize();
    
    while (N--) {
        int num, strike, ball;
        
        cin >> num >> strike >> ball;
        
        solution(num, strike, ball);
        
    }
    
    int cnt = 0;
    
    for(int i = 100; i <= 999; i++) {
        if(arr[i] == true) {
            cnt++;
        }
    }
    
    cout << cnt;
    
    return 0;
}
