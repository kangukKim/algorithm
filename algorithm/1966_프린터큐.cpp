#include<iostream>
#include<queue>
using namespace std;
struct value {
	int importance;
	bool isMain = false;
};
int T, N, M;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N >> M;
		priority_queue<int>pq;
		queue<value>q;
		for (int j = 0; j < N; j++) {
			value v;
			cin >> v.importance;
			pq.push(v.importance);
			if (j == M)v.isMain = true;
			q.push(v);
		}
		int cnt = 0;
		while (!q.empty()) {
			if (pq.top() == q.front().importance) {
				if (q.front().isMain == true) {
					cnt++;
					cout << cnt << '\n';
					break;
				}
				else {
					cnt++;
					q.pop();
					pq.pop();
				}
			}
			else {
				value tmp = q.front();
				q.pop();
				q.push(tmp);
			}
		}
	}
	return 0;
}