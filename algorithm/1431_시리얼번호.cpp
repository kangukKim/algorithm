#include<iostream>
#include<algorithm>	
#include<vector>
#include<string>
using namespace std;
bool cmp(string& a, string& b) {
	if (a.size() != b.size())
		return a.size()<b.size();
	else {
		int a_sz = 0;
		int b_sz = 0;
		for (int i = 0; i < a.size(); i++) {
			if ('0'<a[i]&&a[i]<='9')
				a_sz += a[i]-'0';
			if ('0' < b[i] && b[i] <= '9')
				b_sz += b[i]-'0';
		}
		if (a_sz != b_sz) {
			return a_sz < b_sz;
		}
		else {
			return a < b;
		}
	}
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<string>v;
	while (n--) {
		string s;
		cin >> s;
		v.push_back(s);
	}
	sort(v.begin(), v.end(), cmp);
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << '\n';
	}
	return 0;
}