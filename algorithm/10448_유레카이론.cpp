#include<iostream>
using namespace std;
int getT(int num) {
    return num * (num+1) / 2;
}

bool checkT(int num) {
    for(int i = 1; i < num; i++) {
        for(int j = i; j < num; j++) {
            for(int z = j; z < num; z++) {
                if(getT(i) + getT(j) + getT(z) == num) {
                    return true;
                }
            }
        }
    }
    return false;
}
int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int T;
    cin >> T;
    
    while(T--) {
        int num;
        cin >> num;
        if(checkT(num)) {
            cout << "1" << endl;
        } else {
            cout << "0" << endl;
        }
    }
    return 0;
}
