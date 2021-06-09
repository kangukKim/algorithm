#include<iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, K;
	cin >> N >> K;
	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		if (N % i == 0) {
			cnt++;
		}
		if (cnt == K) {
			cout << i;
			break;
		}
	}
	if (cnt < K) {
		cout << "0";
	}
	return 0;
}