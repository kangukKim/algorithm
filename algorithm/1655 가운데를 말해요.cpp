#include<iostream>
#include<queue>
using namespace std;
priority_queue<int, vector<int>, less<int>>maxHeap;
priority_queue<int, vector<int>, greater<int>>minHeap;
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		if (maxHeap.empty()) {
			maxHeap.push(num);
		}
		else if (maxHeap.size() == minHeap.size()) {
			maxHeap.push(num);
		}
		else {
			minHeap.push(num);
		}
		if (!maxHeap.empty() && !minHeap.empty() && maxHeap.top() > minHeap.top()) {
			int tmp1 = minHeap.top();
			int tmp2 = maxHeap.top();
			minHeap.pop();
			minHeap.push(tmp2);
			maxHeap.pop();
			maxHeap.push(tmp1);
		}
		cout << maxHeap.top() << '\n';
	}

	return 0;
}