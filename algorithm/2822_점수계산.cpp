#include<iostream>
#include<algorithm>
using namespace std;
bool compare(pair<int, int>& a, pair<int, int>& b) {
	return a.second > b.second;
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	pair<int,int> arr[8];
	int hard;
	for (int i = 0; i < 8; i++) {
		cin >> hard;
		arr[i] = make_pair(hard, i + 1);
	}
	sort(arr, arr + 8, greater<pair<int,int>>());

	int sum = 0;
	for (int i = 0; i < 5; i++) {
		sum += arr[i].first;
	}
	cout << sum << '\n';
	sort(arr, arr + 5, compare);
	for (int i = 4; i >= 0; i--) {
		cout << arr[i].second << ' ';
	}
	return 0;
}