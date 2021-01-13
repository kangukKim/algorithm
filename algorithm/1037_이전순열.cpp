#include<iostream>
#include<algorithm>
#include<functional>
using namespace std;

int n;
int arr[10001];
bool desc(int a, int b) {
	return a > b;
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int idx = n - 1;
	if (n == 1) {
		cout << "-1" << endl;
		return 0;
	}
	while (1) {
		if (arr[idx] < arr[idx - 1]) {
			idx--;
			break;
		}
		idx--;
		if (idx == 0) {
			cout << "-1" << endl;
			return 0;
		}
	}
	int idx2 = n - 1;
	while (1) {
		if (arr[idx2] < arr[idx]) {
			swap(arr[idx2], arr[idx]);
			break;
		}
		idx2--;
	}
	sort(arr+idx+1, arr+n, desc);
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	return 0;
}