#include<iostream>
#include<string>
using namespace std;
char* N;
int  M;
int arr[12] = { 1 };
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int num;
		cin >> num;
		arr[num] = 0;
	}
	if (N - '0' == 1) {

	}

}