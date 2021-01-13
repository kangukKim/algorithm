/*
입력값 보다 하나 더 작은걸 출력하는 문제
뒤에서 부터 탐색하면서 앞 숫자가 자기보다 크면안됨
앞 숫자가 자기보다 클 경우엔?
또 뒤에서 부터 탐색을 하면서 처음으로 앞 숫자보다 작은 수가 나오면 위치를 바꿔준다
그 후 앞 숫자 뒤에부터 끝까지 내림차순 정렬을 해주면 정답!
*/


#include<iostream>
#include<algorithm>
#include<functional>
using namespace std;

int n;
int arr[10001];
bool desc(int a, int b) {
	return a > b;
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int idx = n - 1;
	if (n == 1) {
		cout << "-1" << endl;
		return 0;
	}
	while (1) {
		if (arr[idx] < arr[idx - 1]) {
			idx--;
			break;
		}
		idx--;
		if (idx == 0) {
			cout << "-1" << endl;
			return 0;
		}
	}
	int idx2 = n - 1;
	while (1) {
		if (arr[idx2] < arr[idx]) {
			swap(arr[idx2], arr[idx]);
			break;
		}
		idx2--;
	}
	sort(arr+idx+1, arr+n, desc);
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	return 0;
}