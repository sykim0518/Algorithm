#include <iostream>
#include <vector>
#include <queue> 
using namespace std;

int N, M;
vector<vector<int>> map;
vector<vector<int>> visit;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int BFS(int x, int y)
{
	queue<pair<int, int>> q;
	q.push({ x,y });
	visit[x][y] = 1;

	while (!q.empty())
	{
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();

		if (cx == N && cy == M) return visit[cx][cy];
		for (int i=0;i<4;i++)
		{
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx<1 || nx>N || ny<1 || ny>M) continue;
			if (visit[nx][ny]) continue;
			if (map[nx][ny] == 1)
			{
				q.push({ nx,ny });
				visit[nx][ny] = visit[cx][cy] + 1;
			}
		}
	}
}

int main()
{
	cin >> N >> M;
	map = vector<vector<int>>(N+1, vector<int>(M+1, 0));
	visit = vector<vector<int>>(N+1, vector<int>(M+1, 0));

	for (int i=1;i<=N;i++)
	{
		for (int j=1;j<=M;j++)
		{
			scanf_s("%1d", &map[i][j]);
		}
	}

	cout<<BFS(1,1)<<endl;
	return 0;
}