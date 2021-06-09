#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/* 각 인덱스에서 연결가능한 선의 개수를 모두 구하고 마지막에 전체에서 가장 큰 연결가능한 선의 개수를 빼면 없애야할 선의 수가 나온다*/

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<pair<int, int>>v;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back(make_pair(a, b));
	}
	sort(v.begin(), v.end());
	int dp[101];
	for (int i = 0; i < n; i++) {
		dp[i] = 1;
		for (int j = i - 1; j >= 0; j--) {
			if (v[i].second > v[j].second) {
				if (dp[j] >= dp[i]) {
					dp[i] = dp[j] + 1;
				}
			}
		}
	}
	int maxSz = -1;
	for (int i = 0; i < n; i++) {
		maxSz = max(maxSz, dp[i]);
	}
	cout << n - maxSz;


	return 0;


}