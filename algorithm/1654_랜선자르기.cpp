#include<iostream>
#include<algorithm>
using namespace std;
long long num[10001];
int k, n;
long long	high = 0, mid, low = 1;
long long maxNum;
void cnt() {
	while (low<=high) {
		mid = (high + low) / 2;
		long long cnt = 0;
		for (int i = 0; i < k; i++) {
			cnt += num[i] / mid;
		}
		if (cnt < n) {
			high = mid-1;
		}
		else {
			maxNum = max(mid,maxNum);
			low = mid+1;
		}
	}
	return;

}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> k >> n;
	for (int i = 0; i < k; i++) {
		cin >> num[i];
		high = max(num[i], high);
	}
	cnt();
	cout << maxNum;
	return 0;
}