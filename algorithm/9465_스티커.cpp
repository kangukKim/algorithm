#include<iostream>
#include<algorithm>
using namespace std;
int T, n;
int arr[2][100001];
int dp[2][100001];
void bottomup() {
	dp[0][1] = arr[0][1];
	dp[0][2] = arr[0][2]+arr[1][1];
	dp[1][1] = arr[1][1];
	dp[1][2] = arr[1][2]+arr[0][1];
	for (int t= 3; t <= n; t++) {
		dp[0][t] = arr[0][t] + max(dp[1][t - 2], dp[1][t - 1]);
		dp[1][t] = arr[1][t] + max(dp[0][t - 2], dp[0][t - 1]);
	}
	cout << max(dp[0][n], dp[1][n]) <<'\n';
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> n;
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < n; k++) {
				cin >> arr[j][k + 1];
			}
		}
		bottomup();
	}
	return 0;
}