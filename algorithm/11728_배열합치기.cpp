#include<iostream>
#include<vector>	
#include<algorithm>
using namespace std;
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	vector <int> v;
	for (int i = 0; i < n + m; i++) {
		int n;
		cin >> n;
		v.push_back(n);
	}
	sort(v.begin(), v.end(), less<int>());
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << ' ';
	}
	return 0;
}