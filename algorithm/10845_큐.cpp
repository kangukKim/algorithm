#include<iostream>
#include<vector>
using namespace std;

vector<int>queue;

int front_idx = 0;
int tail_idx = -1;

bool empty() {
    if(front_idx - tail_idx == 1) { //empty case
        return 1;
    } else {
        return 0;
    }
}

int main () {
    int N;
    cin >> N;
        
    for (int i = 0; i < N; i++) {
        string order;
        cin >> order;
        if(order == "push") {
            int num;
            cin >> num;
            queue.push_back(num);
            tail_idx += 1;
        } else if(order == "empty") {
            if(!empty()) {
                cout << "0" << endl;
            } else {
                cout << "1" << endl;
            }
        } else if(order == "front") {
            if(!empty()) {
                cout << queue.at(front_idx) << endl;
            } else {
                cout << "-1" << endl;
            }
        } else if(order == "back") {
            if(!empty()) {
                cout << queue.at(tail_idx) << endl;
            } else {
                cout << "-1" << endl;
            }
        } else if(order == "pop") {
            if(!empty()) {
                cout << queue.at(front_idx) << endl;
                front_idx++;
            } else {
                cout << "-1" << endl;
            }
        } else if (order == "size") {
            cout << tail_idx - front_idx + 1 << endl;
        }
    }
    return 0;
}
