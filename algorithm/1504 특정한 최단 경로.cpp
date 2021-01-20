#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
#define INF 987654321
int N, E,v1,v2;
vector<pair<int, int> >v[801];
int dist[801];
void dijkstra(int start) {
	priority_queue<pair<int, int> >pq;
	dist[start] = 0;
	pq.push(make_pair(0, start));
	while (!pq.empty()) {
		int current = pq.top().second;
		int weight = -pq.top().first;
		pq.pop();
		for (int i = 0; i<v[current].size(); i++) {
			int next = v[current][i].first;
			int nWeight = v[current][i].second + weight;
			if (dist[next] > nWeight) {
				dist[next] = nWeight;
				pq.push(make_pair(-nWeight, next));
			}
		}
	}
}
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int a, b, c;
	cin >> N >> E;
	for (int i = 0; i < E; i++) {
		cin >> a >> b >> c;
		v[a].push_back(make_pair(b, c));
		v[b].push_back(make_pair(a, c));
	}
	cin >> v1 >> v2;
	for (int i = 1; i <= N; i++) {
		dist[i] = INF;
	}
	dijkstra(1);
	if (dist[v1] == INF || dist[v2] == INF) {
		cout << "-1" << endl;
		return 0;
	}
	int final_a = dist[v1];
	int final_b = dist[v2];
	for (int i = 1; i <= N; i++) {
		dist[i] = INF;
	}
	dijkstra(v1);
	int a_b = dist[v2];
	final_a = final_a + a_b;
	final_b = final_b + a_b + dist[N];
	if (a_b == INF || final_b >= INF) {
		cout << "-1" << endl;
		return 0;
	}
	for (int i = 1; i <= N; i++) {
		dist[i] = INF;
	}
	dijkstra(v2);
	final_a = final_a + dist[N];
	cout << min(final_a, final_b);
}