#include<iostream>
using namespace std;
struct Dir {
	int y, x;
};
Dir moveDir[4] = { {1,0},{-1,0},{0,1},{0,-1} };
bool arr[500][500];
bool visited[500][500];
int n, m;
int maxSize=0;
int cnt=0;
int area;
void dfs(int i, int j) {
	visited[i][j] = true;
	area++;
	for (int idx = 0; idx < 4; idx++) {
		int nextY = i + moveDir[idx].y;
		int nextX = j + moveDir[idx].x;
		if (nextX >= 0 && nextY >= 0 && nextX < m && nextY < n) {
			if (!visited[nextY][nextX] && arr[nextY][nextX]) {
				dfs(nextY, nextX);
			}

		}
	}

}
int main() {
	ios_base::sync_with_stdio(0); 
	cin.tie(0);


	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!visited[i][j] && arr[i][j]) {
				area = 0;
				dfs(i, j);
				cnt++;
				if (area > maxSize) {
					maxSize = area;
				}
			}
		}
	}
	cout << cnt << '\n'<<maxSize<<'\n';
	return 0;
}