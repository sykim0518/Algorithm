#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX 20001
#define INF 999999999

int V, E, K;
vector<pair<int, int>> adj[MAX];
priority_queue<pair<int, int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

vector<int> Dijk(int start)
{
	vector<int> dist(V+1, INF);
	//(1) 시작 정점 초기화
	dist[start] = 0;
	pq.push({ 0,start });
	
	while (!pq.empty())
	{
		// (2) 최소 정점을 선택하여 현재 정점으로 초기화
		int current = pq.top().second;
		int current_cost =pq.top().first;
		pq.pop();

		for (int i=0;i<adj[current].size();i++)
		{
			// (3) 인접한 정점의 최단거리 갱신
			int next = adj[current][i].first;
			int next_cost = current_cost+adj[current][i].second;
			if (dist[next] > next_cost)
			{
				dist[next] = next_cost;
				pq.push({ next_cost, next });
			}
		}
	}
	return dist;
}

int main()
{
	cin >> V >> E >> K;
	for (int i=0;i<E;i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({ b,c });
	}

	vector<int> dist=Dijk(K);
	for (int i=1;i<dist.size();i++)
	{
		if (dist[i] == INF) cout << "INF" << "\n";
		else cout << dist[i] <<" \n";
	}
	return 0;
}