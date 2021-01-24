#include<iostream>
#include<algorithm>
using namespace std;
int dp[10001];
bool arr[100001];
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n;i++) {
		int num;
		cin >> num;
		arr[num] = 1;
	}
	for (int i = 1; i <= k; i++) {
		if (arr[i] == 1)
			dp[i] = 1;
		else {
			for (int j = 1; j < k; j++) {
				if (dp[i - j] != 0 && dp[j] != 0) {
					if (dp[i] == 0) {
						dp[i] = dp[i - j] + dp[j];
					}
					else {
						dp[i] = min(dp[i], dp[i - j] + dp[j]);
					}
				}
			}
		}
	}
	if (dp[k] == 0)
		cout << "-1";
	else
		cout << dp[k];
}