//queue를 활용하여 O(N)시간 안에 해결해야함
//Brute-force로 진행할 경우 시간초과 뜸

#include<iostream>
#include<queue>

using namespace std;

string student[300010];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    
    ios_base::sync_with_stdio(false);
    
    int N, K;
    
    cin >> N >> K;
    
    queue<int>Q[25];
    
    
    for(int i = 1; i <= N; i++) {
        string s;
        cin >> s;
        student[i] = s;
    }
    long long cnt = 0;
    
    for(int i = 1; i <= N; i++) {
      
        int Len = student[i].length();
        
        while(!Q[Len].empty() && i - Q[Len].front() > K) Q[Len].pop();
        
        cnt += Q[Len].size();
        
        Q[Len].push(i);
        
    }
    
    

    
    cout << cnt;
    return 0;
}
