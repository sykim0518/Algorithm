#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M, V;
vector<vector<int>> adj;
vector<int> visit;
vector<int> order;

void DFS(int start)
{
	visit[start] = 1;
	order.push_back(start);
	for (int i=0;i<adj[start].size();i++)
	{
		if (adj[start][i] == 1 && !visit[i])
		{
			DFS(i);
		}
	}
}

void BFS(int start)
{
	queue<int> q;
	q.push(start);
	visit[start] = 1;

	while (!q.empty())
	{
		int current = q.front();
		q.pop();
		order.push_back(current);
		for (int i=0;i<adj[current].size();i++)
		{
			if (adj[current][i]==1&&!visit[i])
			{
				q.push(i);
				visit[i] = 1;
			}
		}
	}
}

void PrintOrder()
{
	for (int i=0;i<order.size();i++)
	{
		cout << order[i] << " ";
	}
	cout << endl;
}

void initVec()
{
	visit = vector<int>(N+1, 0);
	order.clear();
}

int main()
{
	cin >> N >> M >> V;
	adj = vector<vector<int>>(N+1, vector<int>(N+1, 0));
	for (int i=0;i<M;i++)
	{
		int a, b;
		cin >> a >> b;
		adj[a][b] = 1;
		adj[b][a] = 1;
	}

	initVec();
	DFS(V);
	PrintOrder();

	initVec();
	BFS(V);
	PrintOrder();

	return 0;
}