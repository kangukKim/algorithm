#include<iostream>
using namespace std;

int N, M, x, y, K;
int arr[20][20];
int order[1000];

struct dice {
	int above=0, bottom=0, north=0, east=0, west=0, south=0;
};
dice d;
void travel() {
	for (int i = 0; i < K; i++) {
		if (order[i] == 1) {
			if (y + 1 >= M) {
				continue;
			}
			y++;
			int tmp = d.east;
			d.east = d.above;
			d.above = d.west;
			d.west = d.bottom;
			d.bottom = tmp;
			cout << d.above << '\n';
		}
		if (order[i] == 2) {
			if (y - 1 < 0) {
				continue;
			}
			y--;
			int tmp = d.above;
			d.above = d.east;
			d.east = d.bottom;
			d.bottom = d.west;
			d.west = tmp;
			cout << d.above << '\n';
		}
		if (order[i] == 3) {
			if (x - 1 < 0) {
				continue;
			}

			x--;
			int tmp = d.north;
			d.north = d.above;
			d.above = d.south;
			d.south = d.bottom;
			d.bottom = tmp;
			cout << d.above << '\n';
		}
		if (order[i] == 4) {
			if (x + 1 >= N) {
				continue;
			}
			x++;
			int tmp = d.south;
			d.south = d.above;
			d.above = d.north;
			d.north = d.bottom;
			d.bottom = tmp;
			cout << d.above << '\n';
		}
		if (arr[x][y] == 0) {
			arr[x][y] = d.bottom;
		}
		else {
			d.bottom = arr[x][y];
			arr[x][y] = 0;
		}
	}
}
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N >> M >> x >> y >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < K; i++) {
		cin >> order[i];
	}
	d.bottom = arr[x][y];
	if (d.bottom != 0)
		arr[x][y] = 0;
	travel();
	return 0;
}