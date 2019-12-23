#include <iostream>
#include <string.h>
using namespace std;

int T;
int H, W;
int map[21][21];
int cover[4][3][2]=
{
	{{0,0},{1,0},{1,-1}},
	{{0,0},{1,0},{1,1}},
	{{0,0},{0,1},{1,1}},
	{{0,0}, {0,1},{1,0}}
};

bool set(int type, int x, int y, int flag)
{
	bool ok=true;
	for (int i=0;i<3;i++)
	{
		int nx = x + cover[type][i][0];
		int ny = y + cover[type][i][1];
		if (nx < 0 || nx >= H || ny < 0 || ny >= W)
			ok=false;
		else if ((map[nx][ny] += flag) > 1)
			ok=false;
	}
	return ok;
}

int isCover()
{
	// 아직 채우지 못한칸 중 가장 윗줄 왼쪽 칸을 찾는다
	int x = -1;
	int y = -1;
	for (int h=0;h<H;h++)
	{
		for (int w=0;w<W;w++)
		{
			if (map[h][w] == 0)
			{
				x = h;
				y = w;
				break;
			}
		}
		if (y != -1) break;
	}

	//기저사례: 모든 칸을 채운 경우, return 1
	if (y == -1) return 1;

	int ans = 0;
	for (int type=0;type<4;type++)
	{
		// type형태로 보드를 덮을 수 있으면, 재귀호출
		if (set(type, x, y, 1))
			ans += isCover();
		//덮었던 블록들을 치운다
		set(type, x, y, -1);
	}
	return ans;
}

int main()
{
	cin >> T;
	for (int t=1;t<=T;t++)
	{
		memset(map, 0, sizeof(map));
	
		cin >> H >> W;
		for (int h=0;h<H;h++)
		{
			for (int w=0;w<W;w++)
			{
				char c;
				cin >> c;
				if (c == '#') map[h][w] = 1;
			}
		}
		cout << isCover() << endl;
	}
	return 0;
}