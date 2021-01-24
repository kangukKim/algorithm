#include<iostream>
# define MOD 1000000000
using namespace std;
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int arr[10][101];
	arr[0][1] = 0;
	for (int i = 1; i <= 9; i++) {
		arr[i][1] = 1;
	}
	int n;
	cin >> n;
	int sum = 0;
	for (int i = 2; i <= n; i++) {
		arr[9][i] = arr[8][i - 1];
		arr[0][i] = arr[1][i - 1];
		for (int j = 1; j <= 8; j++) {
			arr[j][i] = (arr[j - 1][i - 1] + arr[j + 1][i - 1])%MOD;
		}
	}
	if (n == 1) {
		cout << "9";
	}
	else {
		for (int i = 0; i <= 9; i++) {
			sum = (sum+arr[i][n]) % MOD;
		}
		cout << sum;
	}
	
	return 0;
}