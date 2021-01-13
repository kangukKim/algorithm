#include<iostream>
#include<algorithm>
using namespace std;

int N;
int arr[100];
int op[4];
int minResult=1000000000+1, maxResult=-1000000000-1;
int total;
void dfs(int plus, int minus, int mutilply, int divide, int cnt, int sum) {
	if (cnt == N) {
		maxResult = max(sum, maxResult);
		minResult = min(sum, minResult);

	}
	if (plus > 0) {
		dfs(plus - 1, minus, mutilply, divide, cnt + 1, sum + arr[cnt]);
	}
	if (minus > 0) {
		dfs(plus, minus-1, mutilply, divide, cnt + 1, sum - arr[cnt]);
	}
	if (mutilply > 0) {
		dfs(plus, minus, mutilply-1, divide, cnt + 1, sum * arr[cnt]);
	}
	if (divide > 0) {
		dfs(plus, minus, mutilply, divide-1, cnt + 1, sum / arr[cnt]);
	}

}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < 4; i++) {
		cin >> op[i];
	}
	dfs(op[0], op[1], op[2], op[3], 1, arr[0]);
	
	cout << maxResult << '\n' << minResult;
	return 0;
}