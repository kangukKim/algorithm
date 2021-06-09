#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string bigNumAdd(string a, string b) {
	long long sum = 0;
	string result;
	while (!a.empty() || !b.empty() || sum) {
		if (!a.empty()) {
			sum += a.back() - '0';
			a.pop_back();
		}
		if (!b.empty()) {
			sum += b.back() - '0';
			b.pop_back();
		}
		result.push_back((sum % 10)+'0');
		sum /= 10;
	}
	reverse(result.begin(), result.end());
	return result;
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	string d[251];
	d[0] = '1';
	d[1] = '1';
	d[2] = '3';
	for (int i = 3; i <= 250; i++) {
		d[i] = bigNumAdd(bigNumAdd(d[i - 2],d[i-2]),d[i - 1]);
	}
	while (1) {
		int n;
		cin >> n;
		if (cin.fail() != false) break;
		cout << d[n] <<endl;
	}
	return 0;
}