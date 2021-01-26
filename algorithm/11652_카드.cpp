#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
bool cmp(pair<long long, int>& a, pair<long long, int>& b) {
	if (a.second == b.second) {
		return b.first > a.first;
	}
	return a.second > b.second;
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n;
	map<long long,int>m;
	cin >> n;
	for (int i = 0; i < n; i++) {
		long long num;
		cin >> num;
		m[num]++;
	}
	vector<pair<long long, int>>v(m.begin(),m.end());
	sort(v.begin(), v.end(), cmp);
	cout << v[0].first;
	return 0;
}