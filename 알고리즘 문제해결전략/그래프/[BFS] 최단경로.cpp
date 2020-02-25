#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> adj;
// ������������ �� ���������� �ִ� �Ÿ��� ���
// distance[i] : start���� i ���� �ִܰŸ�
// parent[i] : �ʺ� �켱 Ž�� Ʈ������ i�� �θ��� ��ȣ, ��Ʈ�� ���� �ڽ��� ��ȣ
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
