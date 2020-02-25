#include <iostream>
#include <queue>
using namespace std;

int N, M;
int BOX[1001][1001];
bool VISITED[1001][1001];
int nonrippen = 0;
int day = 0;
int ans;

int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

// 위치와 날짜를 저장하는 구조체
struct Position
{
	int x, y, day;
	Position(int x, int y, int day)
	{
		this->x = x;
		this->y = y;
		this->day = day;
	}
};

void BFS()
{
	// (1) VISITED 배열 초기화
	for (int x = 0; x < N; x++)
	{
		for (int y = 0; y < M; y++)
		{
			VISITED[x][y] = false;
		}
	}
	// (2) 시작 정점을 큐에 저장
	queue <Position> queue;
	for (int x = 0; x < N; x++)
	{
		for (int y = 0; y < M; y++)
		{
			if (BOX[x][y] == 1)
				queue.push(Position(x, y, 0));
		}
	}
	Position start(0, 0, 0);

	//(3)인접 정점이 방문되지 않았을 경우 큐에 저장
	while (!queue.empty())
	{
		start = queue.front();
		queue.pop();
		for (int i = 0; i < 4; i++)
		{
			//상자범위 내에 있는 인접한 토마토만 고려 
			if ((start.x + dx[i] >= 0 && start.x + dx[i] < N) && (start.y + dy[i] >= 0 && start.y + dy[i] < M))
			{
				//인접한 토마토가 익지않고 방문되지 않았을 때만 고려
				if (BOX[start.x + dx[i]][start.y + dy[i]] == 0 && VISITED[start.x + dx[i]][start.y + dy[i]] == false)
				{
					//익은 토마토의 영향을 받아 익게됨
					BOX[start.x + dx[i]][start.y + dy[i]] = 1;
					VISITED[start.x + dx[i]][start.y + dy[i]] = true;
					queue.push(Position(start.x + dx[i], start.y + dy[i], start.day + 1));
					nonrippen--;
				}
			}
		}
		//하루가 지남
		ans = start.day;
	}
	if (nonrippen == 0)
		cout << ans;
	else
		cout << "-1";
}

int main()
{
	cin >> M >> N;
	for (int x = 0; x < N; x++)
	{
		for (int y = 0; y < M; y++)
		{
			cin >> BOX[x][y];
			if (BOX[x][y] == 0) nonrippen++;
		}
	}

	// 모든 토마토가 익어있는 상태
	if (nonrippen == 0)
	{
		cout << "0";
		return 0;
	}
	// 안익은 토마토가 하나라도 있는 상태
	else
	{
		BFS();
	}

	return 0;
}