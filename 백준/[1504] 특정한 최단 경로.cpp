#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define INF 999999
#define MAX 801

int N, E;
vector<pair<int, int>> adj[MAX];
int V1, V2;
int ans = INF;

vector<int> Dijk(int start)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	vector<int> dist(N + 1, INF);
	dist[start] = 0;
	pq.push({ 0,start });

	while (!pq.empty())
	{
		int current = pq.top().second;
		int current_cost = pq.top().first;
		pq.pop();

		for (int i = 0; i < adj[current].size(); i++)
		{
			int next = adj[current][i].first;
			int next_cost = current_cost + adj[current][i].second;
			if (dist[next] > next_cost)
			{
				dist[next] = next_cost;
				pq.push({ next_cost,next });
			}
		}
	}
	return dist;
}

int main()
{
	cin >> N >> E;
	for (int i = 0; i < E; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({ b,c });
		adj[b].push_back({ a,c });
	}
	cin >> V1 >> V2;
	vector<int> dist1 = Dijk(1);
	vector<int> dist2 = Dijk(V1);
	vector<int> dist3 = Dijk(V2);
	ans = min(ans, dist1[V1] + dist2[V2] + dist3[N]);

	vector<int> dist4 = Dijk(1);
	vector<int> dist5 = Dijk(V2);
	vector<int> dist6 = Dijk(V1);
	ans = min(ans, dist4[V2] + dist5[V1] + dist6[N]);

	if (ans == INF) cout << -1 << endl;
	else cout << ans << endl;
	return 0;
}