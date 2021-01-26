#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	vector<int>w;
	vector<int>k;
	for (int i = 0; i < 10; i++) {
		int n;
		cin >> n;
		w.push_back(n);
	}
	for (int i = 0; i < 10; i++) {
		int n;
		cin >> n;
		k.push_back(n);
	}
	sort(w.begin(), w.end(), greater<int>());
	sort(k.begin(), k.end(), greater<int>());
	int w_sum = w[0] + w[1] + w[2];
	int k_sum = k[0] + k[1] + k[2];
	cout << w_sum << " " << k_sum;
	return 0;
}