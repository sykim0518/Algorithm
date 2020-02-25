#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> adj;
// 시작정점부터 각 정점까지의 최단 거리를 계산
// distance[i] : start부터 i 까지 최단거리
// parent[i] : 너비 우선 탐색 트리에서 i의 부모의 번호, 루트인 경우는 자신의 번호
void BFS_shortest(int start, vector<int> distance, vector<int> parent)
{
	distance = vector<int>(adj.size(), -1);
	parent = vector<int>(adj.size(), -1);

	queue<int> q;
	distance[start] = 0;
	parent[start] = start;
	q.push(start);
	while (!q.empty())
	{
		int current = q.front();
		q.pop();
		for (int i=0;i<adj[current].size();i++)
		{
			int next = adj[current][i];
			if (distance[i] == -1)
			{
				q.push(i);
				distance[i] = distance[current] + 1;
				parent[i] = current;
			}
		}
	}
}
