#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int n, l;

int fun(vector<vector<int>>& map) {
	int temp;
	int error = 1;
	int xresult = 0;
	for (int i = 0; i < n; i++) {
		temp = map[i][0];


		error = 0;
		for (int j = 1; j < n; j++) {
			if (temp == map[i][j])
				continue;

			// 내려가는 방향
			else if (temp == map[i][j] + 1) {
				temp--;
				for (int k = j; k < j + l; k++) {

					if (k >= n) {
						error = 1;
						break;
					}
					if (temp != map[i][k]) {
						error = 1;
						break;
					}
					map[i][k] = -1;
				}
				if (error)
					break;
				else
					j += l - 1;
			}
			// 올라가는 방향
			else if (temp == map[i][j] - 1) {
				temp++;
				for (int k = j - 1; k > j - l - 1; k--) {
					if (k < 0) {
						error = 1;
						break;
					}
					if (temp != map[i][k] + 1) {
						error = 1;
						break;
					}
					map[i][k] = -1;
				}
				if (error)
					break;
			}
			else {
				error = 1;
				break;
			}
		}
		if (error == 0) {
			xresult++;
		}
	}
	return xresult;
}
int main() {
	int temp;

	cin >> n >> l;

	vector<vector<int>> map(n, vector<int>(n, 0));
	vector<vector<int>> xmap(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> temp;
			map[i][j] = temp;
			xmap[j][i] = temp;
		}
	}
	cout << fun(map) + fun(xmap);
	return 0;
}