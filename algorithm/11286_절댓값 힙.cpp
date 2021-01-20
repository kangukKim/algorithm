#include<iostream>
#include<queue>
#include<math.h>
using namespace std;
struct cmp {//����ü © �� �񱳰�� ���� ���ϴ� ���� false�� ������ �ؾ��� ���� ��� �տ��� �ڿ����� �۰� �ϱ� ���ؼ��� a.first>b.first�� false�� �����ԵǹǷ� �̷��� �ؾ���
	bool operator()(pair<int, int>&a, pair<int, int>&b) {
		if (a.first == b.first) {
			return a.second > b.second;
		}
		return a.first > b.first;
	}
};
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	priority_queue<pair<int,int>, vector<pair<int,int>>,cmp>pq;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		if (num == 0) {
			if (pq.empty())
				cout << "0\n";
			else {
				pair<int,int>tmp = pq.top();
				pq.pop();
				if (tmp.second==-1) {
					cout << -tmp.first << '\n';
				}
				else
					cout << tmp.first << '\n';
			}
		}
		else {
			if (num < 0) {
				pq.push(make_pair(abs(num), -1));			}
			else
				pq.push(make_pair(num, 1));
		}
	}
	return 0;
}