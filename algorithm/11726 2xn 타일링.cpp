#include<iostream>
using namespace std;
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	int dp[1001];
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= n; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2])%10007;
	}
	cout << dp[n] << '\n';
	return 0;
}