/* ���ͽ�Ʈ�� �˰��� */
// �ϳ��� �������� �ٸ� ��� ���������� �ִܰŸ�

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX_V 10000
#define INF 999999999

int V; //������ ����
vector<pair<int, int>> adj[MAX_V]; // �׷����� ��������Ʈ

vector<int> dijkstra(int start)
{
	vector<int> dist(V, INF);
	
	dist[start] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push({ 0,start });
	
	while (!pq.empty())
	{
		int cost = -pq.top().first;
		int current = pq.top().second;
		pq.pop();
		
		if (dist[current] < cost) continue;
		for (int i=0;i<adj[current].size();i++)
		{
			int next = adj[current][i].first;
			int nextDist = cost+adj[current][i].second;
			if (dist[next] > nextDist)
			{
				dist[next] = nextDist;
				pq.push({ -nextDist,next });
			}
		}

	}
	return dist;
}
