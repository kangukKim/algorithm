#include<iostream>
#include<queue>
#include<algorithm>
#include<string.h>
using namespace std;
struct Dir {
	int y, x;
};
Dir moveDir[4] = { {1,0},{-1,0},{0,1},{0,-1} };
int N, M;
int arr[8][8];
int arrCopy[8][8];
queue<Dir>q;
queue<Dir>qCopy;
int maxZone;
int safeZone;
void bfs() {
	qCopy = q;
	while (!qCopy.empty()) {
		int sz = qCopy.size();
		while (sz--) {
			for (int i = 0; i < 4; i++) {
				int nextX = qCopy.front().x + moveDir[i].x;
				int nextY = qCopy.front().y + moveDir[i].y;
				if (nextX < M && nextX >= 0 && nextY < N && nextY >= 0) {
					if (arrCopy[nextY][nextX] == 0) {
						arrCopy[nextY][nextX] = 2;
						qCopy.push({ nextY,nextX });
					}
				}

			}
			qCopy.pop();
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arrCopy[i][j] == 0) {
				safeZone++;
			}
		}
	}
	maxZone = max(safeZone, maxZone);
	safeZone = 0;
}

void wall(int cnt) {
	if (cnt == 3) {
		memcpy(arrCopy, arr, sizeof(arr));
		bfs();
		return;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == 0) {
				arr[i][j] = 1;
				wall(cnt + 1);
				arr[i][j] = 0;
			}
		}
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 2) {
				q.push({ i,j });
			}
		}
	}
	wall(0);
	cout << maxZone;
}