#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N;
int cnt = 1;

vector<vector<int>> map;
vector<vector<int>> visit;
vector<int> arr;
priority_queue <int,vector<int>,greater<int>> pq;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

void BFS(int x, int y)
{
	queue<pair<int,int>> q;
	q.push({ x,y});
	visit[x][y] = cnt;

	int res = 0;

	while (!q.empty())
	{
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();
		res++;

		for (int i=0;i<4;i++)
		{
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
			if (visit[nx][ny]) continue;
			if (map[nx][ny]==1)
			{
				visit[nx][ny] = cnt;
				q.push({ nx,ny });
			}
		}
	}
	pq.push(res);
}

int main()
{
	cin >> N;
	map = vector<vector<int>>(N , vector<int>(N, 0));
	visit= vector<vector<int>>(N , vector<int>(N, 0));

	for (int i=0;i<N;i++)
	{
		for (int j=0;j<N;j++)
		{
			scanf("%1d", &map[i][j]);
		}
	}

	for (int i=0;i<N;i++)
	{
		for (int j=0;j<N;j++)
		{
			if (map[i][j] != 0 && visit[i][j]==0)
			{
				BFS(i, j);
				cnt++;
			}
		}
	}

	cout << pq.size()<<endl;
	for (int i = 1; i <cnt; i++)
	{
		cout << pq.top() << endl;
		pq.pop();
	}

	return 0;
}