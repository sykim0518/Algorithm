#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> adj; //������� ǥ��
vector<bool> visit; // ������ �湮 ����
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