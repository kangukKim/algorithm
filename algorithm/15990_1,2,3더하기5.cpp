#include<iostream>
using namespace std;
typedef long long ll;
#define MOD 1000000009
ll dp[100001][4];
void solve(int n) {
	for (int i = 4; i <= n; i++) {
		if (dp[i][1] == 0) {
			dp[i][1] = (dp[i - 1][2] + dp[i - 1][3]) % MOD;

		}
		if (dp[i][2] == 0) {
			dp[i][2] = (dp[i - 2][1] + dp[i - 2][3]) % MOD;

		}
		if (dp[i][3] == 0) {
			dp[i][3] = (dp[i - 3][1] + dp[i - 3][2]) % MOD;

		}
	}
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int T;
	cin >> T;
	dp[1][1] = dp[2][2] = dp[3][1] = dp[3][2] = dp[3][3] = 1;
	for (int i = 0; i < T; i++) {
		int n;
		cin >> n;
		solve(n);
		cout << (dp[n][1] + dp[n][2] + dp[n][3])%MOD<<endl;
	}
}