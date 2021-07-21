#include<iostream>
using namespace std;
int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    int N;
    cin >> N;
    int sum = 0;
    for (int i=1;i<N;i++) {
        sum = i;
        int tmp = i;
        while(tmp>0) {
            sum += tmp % 10;
            tmp /= 10;
        }
        if (sum == N) {
            cout << i;
            return 0;
        }
    }
    
    cout << "0";
    return 0;
}
