#include <iostream>
#include <vector>
#include <queue>
using namespace std;


int N, M;
vector<vector<int>> map;
int dist[1001][1001][2] = { 0 };

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

struct type
{
	int x, y;
	int wall;
};

int BFS(int x, int y)
{
	queue<type> q;
	q.push({ x,y,0 });
	dist[x][y][0] = 1;

	while (!q.empty())
	{
		int cx = q.front().x;
		int cy = q.front().y;
		int cw = q.front().wall;
		q.pop();

		if (cx == N && cy == M) return dist[cx][cy][cw];

		for (int i=0;i<4;i++)
		{
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx<1 || nx>N || ny<1 || ny>M) continue;
			if (dist[nx][ny][cw]) continue;
			if (map[nx][ny] == 0)
			{
				q.push({ nx,ny,cw });
				dist[nx][ny][cw] = dist[cx][cy][cw] + 1;
			}
			else if (map[nx][ny] == 1 && cw == 0)
			{
				q.push({ nx,ny,1});
				dist[nx][ny][1] = dist[cx][cy][cw] + 1;
			}
		}
	}
	return -1;
}

int main()
{
	cin >> N >> M;
	map = vector<vector<int>>(N+1, vector<int>(M+1, 0));
	for (int i=1;i<=N;i++)
	{
		for (int j=1;j<=M;j++)
		{
			scanf("%1d", &map[i][j]);
		}
	}
	
	cout << BFS(1, 1) << endl;
	return 0;
}