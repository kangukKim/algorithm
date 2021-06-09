#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	vector<int>list;
	while (N--) {
		int num;
		cin >> num;
		list.push_back(num);
	}
	sort(list.begin(), list.end(), less<int>());
	cout << list.front() << " " << list.back();
	return 0;
}