#include<iostream>
#include<algorithm>
using namespace std;
int low, mid, high;
int arr[1000001];
void find(int x) {
	while (low <= high) {
		mid = (low + high) / 2;
		if (arr[mid] == x) {
			cout << '1' << '\n';
			return;
		}
		else if (arr[mid] > x) {
			high = mid - 1;

		}
		else {
			low = mid + 1;

		}
	}
	cout << '0' << '\n';
	return;


}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> arr[i];
		}
		sort(arr, arr + N);
		int M;
		cin >> M;
		for (int i = 0; i < M; i++) {
			low = 0;
			high = N - 1;	
			int x;
			cin >> x;
			//if (x > arr[N - 1])
			//	cout << '0' << '\n';
			//else
			find(x);
		}
	}
	return 0;
}