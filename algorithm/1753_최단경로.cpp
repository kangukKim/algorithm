//다익스트라알고리즘

#include<iostream>
#include<queue>
#include<vector>
#define INF 987654321
using namespace std;
int v, e, k;
vector<pair<int, int> >a[20001];//간선정보(도착노드, weight)
int d[20001];//최소비용

void dijkstra(int start) {
	d[start] = 0;
	priority_queue<pair<int, int>>pq;
	pq.push(make_pair(0,start));
	while (!pq.empty()) {
		int current = pq.top().second;
		int weight = -pq.top().first;
		pq.pop();
		if (d[current] < weight)continue;
		for (int i = 0; i < a[current].size(); i++) {
			int next = a[current][i].first;
			int nextWeight = weight+a[current][i].second;
			if (nextWeight < d[next]) {
				d[next] =nextWeight;
				pq.push(make_pair(-nextWeight,next)); 
			}
		}
	}
}
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> v >> e >> k;
	for (int i = 1; i <= v; i++) {
		d[i] = INF;
	}
	for (int i = 0; i < e; i++) {
		int u, b, w;
		cin >> u >> b >> w;
		a[u].push_back(make_pair(b, w));
	}
	dijkstra(k);
	for (int i = 1; i <= v; i++) {
		if (d[i] == INF)
			cout << "INF" << '\n';
		else
			cout << d[i] << '\n';
	}
	return 0;
}