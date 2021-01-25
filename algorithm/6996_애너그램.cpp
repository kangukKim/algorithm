#include<iostream>
#include<string>
#include <algorithm>
using namespace std;
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int T;
	cin >> T;
	while (T--) {
		string a, b;
		cin >> a >> b;
		string a_tmp = a;
		string b_tmp = b;

		sort(a.begin(), a.end());
		sort(b.begin(), b.end());

		if (a == b) {
			cout << a_tmp << " & " << b_tmp << " are anagrams.\n";
		}
		else {
			cout << a_tmp << " & " << b_tmp << " are NOT anagrams.\n";

		}


	}
	return 0;

}