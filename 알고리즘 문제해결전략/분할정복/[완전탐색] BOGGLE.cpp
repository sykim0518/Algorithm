#include <iostream>
#include <vector>
#include <string>
using namespace std;

int T;
char map[6][6];
int voca_num;
vector<string> voca;

const int dx[8] = { -1,0,1,0,-1,-1,1,1 };
const int dy[8] = { 0,1,0,-1,-1,1,1,-1 };


bool sol(string target, pair<int, int> current)
{
	// 기저사례1: 현재 위치가 범위밖이면, 실패
	if (current.first < 1 || current.first>5 || current.second < 1 || current.second>5) return false;
	// 기저사례2: 첫 글자가 일치하지 않으면, 실패
	if (map[current.first][current.second] != target[0]) return false;
	// 기저사례3: 단어 길이가 1이면 성공
	if (target.size() == 1) return true;

	for (int i = 0; i < 8; i++)
	{
		pair<int, int> next = { current.first + dx[i],current.second + dy[i] };
		if (sol(target.substr(1), next)) return true;
	}
	return false;
}


int main()
{
	cin >> T;

	for (int t = 1; t <= T; t++)
	{
		for (int i = 1; i <= 5; i++)
			memset(map, 0, sizeof(char) * 6);
		voca.clear();

		for (int i = 1; i <= 5; i++)
		{
			for (int j = 1; j <= 5; j++)
			{
				cin >> map[i][j];
			}
		}

		cin >> voca_num;
		for (int i = 0; i < voca_num; i++)
		{
			string s;
			cin >> s;
			voca.push_back(s);
		}

		for (int i = 0; i < voca_num; i++)
		{
			bool flag = false;
			for (int x = 1; x <= 5; x++)
			{
				if (flag) break;
				for (int y = 1; y <= 5; y++)
				{
					flag = sol(voca[i], { x,y });

					if (flag)
					{
						cout << voca[i] << " " << "YES" << endl;
						break;
					}
					if (x == 5 && y == 5 && !flag)  cout << voca[i] << " " << "NO" << endl;
				}
			}
		}
	}
	return 0;
}