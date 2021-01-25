#include<iostream>
using namespace std;
int arr[1000001];
int find(int x) {
	if (arr[x] == x)
		return x;
	return arr[x] = find(arr[x]);
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i <= n; i++) {
		arr[i] = i;
	}
	
	for (int i = 0; i < m; i++) {
		int num, a, b;
		cin >> num >> a >> b;
		if (num == 0) {
			int da = find(a);
			int db = find(b);
			if (da > db)
				arr[da] = db;
			else if (da < db)
				arr[db] = da;
		}
		else {
			if (find(a) == find(b))
				cout << "YES\n";
			else
				cout << "NO\n";
		}
	}
	return 0;

}