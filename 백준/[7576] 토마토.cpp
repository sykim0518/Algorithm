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

// ��ġ�� ��¥�� �����ϴ� ����ü
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
	// (1) VISITED �迭 �ʱ�ȭ
	for (int x = 0; x < N; x++)
	{
		for (int y = 0; y < M; y++)
		{
			VISITED[x][y] = false;
		}
	}
	// (2) ���� ������ ť�� ����
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

	//(3)���� ������ �湮���� �ʾ��� ��� ť�� ����
	while (!queue.empty())
	{
		start = queue.front();
		queue.pop();
		for (int i = 0; i < 4; i++)
		{
			//���ڹ��� ���� �ִ� ������ �丶�丸 ��� 
			if ((start.x + dx[i] >= 0 && start.x + dx[i] < N) && (start.y + dy[i] >= 0 && start.y + dy[i] < M))
			{
				//������ �丶�䰡 �����ʰ� �湮���� �ʾ��� ���� ���
				if (BOX[start.x + dx[i]][start.y + dy[i]] == 0 && VISITED[start.x + dx[i]][start.y + dy[i]] == false)
				{
					//���� �丶���� ������ �޾� �ͰԵ�
					BOX[start.x + dx[i]][start.y + dy[i]] = 1;
					VISITED[start.x + dx[i]][start.y + dy[i]] = true;
					queue.push(Position(start.x + dx[i], start.y + dy[i], start.day + 1));
					nonrippen--;
				}
			}
		}
		//�Ϸ簡 ����
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

	// ��� �丶�䰡 �;��ִ� ����
	if (nonrippen == 0)
	{
		cout << "0";
		return 0;
	}
	// ������ �丶�䰡 �ϳ��� �ִ� ����
	else
	{
		BFS();
	}

	return 0;
}