#include<iostream>
#include<algorithm>
using namespace std;
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n, score, p;
	cin >> n >> score >> p;
	int arr[51];
	int cnt;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	if (score <= arr[n] && n==p) {
		cout << "-1";
	}
	else {
		int rank = 1;
		for (int i = 1; i <= n; i++) {
			if (score < arr[i]) {
				rank++;
			}
			else
				break;
		}
		cout << rank;

	}
	return 0;
}