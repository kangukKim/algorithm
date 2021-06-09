#include<iostream>
#include<algorithm>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int total_people = 0;
	int total_list[10];
	for (int i = 0; i < 10; i++) {
		int down, up;
		cin >> down >> up;
		total_people = total_people + up - down;
		total_list[i] = total_people;
	}
	sort(total_list, total_list+10, greater<int>());
	cout << total_list[0];
	return 0;
}