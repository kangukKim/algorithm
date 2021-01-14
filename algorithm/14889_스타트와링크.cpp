#include<iostream>
#include<vector>
#include<stdlib.h>
#include<algorithm>
using namespace std;

int N;
int arr[20][20];

bool chk[20];

vector<int>start;
vector<int>link;

int startSum;
int linkSum;

int minResult = 1000;

void calc() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j <N; j++) {
			if(chk[i]==true&&chk[j]==true)
			startSum += arr[i][j];
			if(chk[i]==false && chk[j]==false)
				linkSum += arr[i][j];
		}
	}
	int result = abs(startSum - linkSum);
	minResult = min(result, minResult);
}

void check(int cnt,int idx) {
	if (cnt == N/2) {
		calc();
		startSum = 0;
		linkSum = 0;
	}
	for (int i = idx; i < N; i++) {
		if (chk[i] == false) {
			chk[i] = true;
			check(cnt + 1,i+1);
			chk[i] = false;
		}

	}
}


int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}
	check(0,0);
	cout << minResult;
}