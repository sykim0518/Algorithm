#include <iostream>
#include <vector>
#include <string>
using namespace std;

int C;
char map[6][6];
int N;
vector<string> voca;

int dx[8] = {-1,-1,-1,0,1,1,1,0};
int dy[8] = {-1,0,1,1,1,0,-1,-1};

bool isRange(int x, int y)
{
	if (x < 0 || x >= 5 || y < 0 || y >= 5) return false;
	return true;
}

bool hasword(string voca,int x,int y)
{
	//기저사례1: 범위 밖이면, return true
	if (!isRange(x, y)) return false;

	//기저사례2: 첫글자가 다르면, return true
	if (voca[0] != map[x][y]) return false;
	
	//기저사례3: 총 글자수가 1이면, return false
	if (voca.size() == 1) return true;

	for (int i = 0; i < 8; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (hasword(voca.substr(1), nx, ny)) return true;
	}
	return false;
}

int main()
{
	cin >> C;
	for (int t=1;t<=C;t++)
	{
		memset(map, 0, sizeof(map));
		voca.clear();

		for (int i=0;i<5;i++)
		{
			for (int j=0;j<5;j++)
			{
				cin >> map[i][j];
			}
		}
		cin >> N;
		for (int i=0;i<N;i++)
		{
			string s;
			cin >> s;
			voca.push_back(s);
		}

		bool flag = false;
		for (int i=0;i<N;i++)
		{
			for (int x=0;x<5;x++)
			{
				for (int y=0;y<5;y++)
				{
					flag=hasword(voca[i],x,y);
					if (flag) break;
				}
				if (flag) break;
			}
			if (flag)
				cout << voca[i] << " " << "YES"<<endl;
			else
				cout << voca[i] << " " << "NO"<<endl;
		}
	}
	return 0;
}