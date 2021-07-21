#include<iostream>
using namespace std;
long long dp[81];
void fibonacci(int N) {
	for (int i = 3; i <= N; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int N;
	cin >> N;
	dp[1] = 1;
	dp[2] = 1;
	fibonacci(N);
	cout << (dp[N]+dp[N-1]) * 2 + dp[N] * 2;
	return 0;
}