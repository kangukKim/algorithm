#include<iostream>
#include<algorithm>
using namespace std;
int dp[1000001];
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 1;
	for (int i = 4; i <= n; i++) {
		if (i % 3 == 0) {
			if (i % 2 == 0) {
				dp[i] = min({ dp[i / 3], dp[i / 2], dp[i - 1] }) + 1;
			}
			else {
				dp[i] = min(dp[i / 3], dp[i - 1]) + 1;
			}
		}
		else {
			if (i % 2 == 0) {
				dp[i] = min(dp[i / 2], dp[i - 1]) + 1;
			}
			else {
				dp[i] = dp[i - 1] + 1;
			}
		}
	}
	cout << dp[n];
	return 0;
}