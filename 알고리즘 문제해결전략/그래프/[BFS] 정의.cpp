#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> adj; //인접행렬 표현
vector<bool> visit; // 정점의 방문 여부
vector<int> order;

vector<int> BFS(int start)
{
	queue<int> q;
	visit[start] = true;
	q.push(start);

	while (!q.empty())
	{
		int current = q.front();
		q.pop();
		order.push_back(current);
		for (int i = 0; i < adj[current].size(); i++)
		{
			int next = adj[current][i];
			if (!visit[i])
			{
				q.push(i);
				visit[i] = true;
			}
		}
	}
	return order;
}