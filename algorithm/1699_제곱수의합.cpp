#include<iostream>
#include<math.h>
using namespace std;
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	int dp[100001] = { 0, };
	for (int i = 1; i <= n; i++) {
		for (int j = sqrt(i); j > 0; j--) {
			if (j * j == i)
				dp[i] = 1;
			else
			{	
				if (dp[i] == 0) {
					dp[i]=dp[i - j * j] + 1;
				}
				else
					dp[i] = min(dp[i], dp[i - j * j] + 1);
			}
	
		}
	}
	cout << dp[n];
	return 0;
}