#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	int v[1001];
	for (int i = 0; i < n; i++) {
		cin >> v[i+1];
	}
	int d[1001];
	for (int i = 1; i <= n; i++) {
		d[i] = 1;
	}
	int maxCnt = 0;
	for (int i = 2; i <= n; i++) {
		for (int j = i - 1; j >= 1; j--) {
			if (v[i] > v[j]) {
				d[i] = max(d[j] + 1, d[i]);
			}
		}
		if (maxCnt < d[i])
			maxCnt = d[i];
	}
	cout << maxCnt;
	return 0;
}