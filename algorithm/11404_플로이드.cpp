#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
#define INF 987654321
int n, m;
int arr[101][101];
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	int a, b, c;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++){
			arr[i][j] = INF;
		}
	}

	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		arr[a][b] = min(arr[a][b], c);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				if(arr[j][i]!=INF && arr[i][k]!=INF)
					arr[j][k] = min(arr[j][k], arr[j][i] + arr[i][k]);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j||arr[i][j]== INF) {
				cout << "0" << " ";
			}
			else
				cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}