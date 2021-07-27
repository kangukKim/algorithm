#include<iostream>
using namespace std;
bool word[100];


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    string s;
    int N;
    
    cin >> s >> N;
    
    string arr[100];

    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    word[s.length()] = 1;
    for(int i = s.length()-1; i >= 0; i--) {
        for(int j = 0; j < N; j++) {
            if(s.find(arr[j], i) == i && word[i + arr[j].length()] == 1) {
                word[i] = 1;
                break;
            }
        }
    }
    
    cout << word[0];
    
}
