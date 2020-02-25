#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int T, M, N, K;
vector<vector<int>> map;
vector<vector<int>> visit;
int ans;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

void BFS(int x, int y)
{
	queue<pair<int, int>>  q;
	q.push({ x,y });
	visit[x][y] = 1;

	while (!q.empty())
	{
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();

		for (int i=0;i<4;i++)
		{
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue;
			if (visit[nx][ny]) continue;
			if (map[nx][ny] == 1)
			{
				q.push({ nx,ny });
				visit[nx][ny] = 1;
			}
		}
	}
}

int main()
{
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		cin >> M >> N >> K;
		map = vector<vector<int>>(M, vector<int>(N, 0));
		visit = vector<vector<int>>(M, vector<int>(N, 0));
		ans = 0;

		for (int i=0;i<K;i++)
		{
			int a, b;
			cin >> a >> b;
			map[a][b] = 1;
		}

		for (int i=0;i<M;i++)
		{
			for (int j=0;j<N;j++)
			{
				if (map[i][j] != 0 && visit[i][j]==0)
				{
					BFS(i, j);
					ans++;
				}
			}
		}
		cout << ans  << endl;
	}
	return 0;
}