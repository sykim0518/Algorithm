#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int T;
int N, M;
bool isFriend[10][10] = { false };
bool isPair[10] = { false };

int sol(bool isPair[10])
{
	// 남은 학생들 중 가장 번호가 빠른 학생을 찾는다
	int notPair = -1;
	for (int i = 0; i < N; i++)
	{
		if (!isPair[i])
		{
			notPair = i;
			break;
		}
	}

	// 기저사례: 모든 학생이 짝을 찾았으면, 종료
	if (notPair == -1) return 1;

	int ans = 0;
	// 짝지을 학생 정하기
	for (int p = notPair + 1; p < N; p++)
	{
		if (!isPair[p] && isFriend[notPair][p])
		{
			isPair[notPair] = isPair[p] = true;
			ans += sol(isPair);
			isPair[notPair] = isPair[p] = false;
		}
	}
	return ans;
}

int main()
{
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		cin >> N >> M;
		memset(isFriend, false, sizeof(isFriend));
		memset(isPair, false, sizeof(isPair));

		for (int m = 0; m < M; m++)
		{
			int x, y;
			cin >> x >> y;
			isFriend[x][y] = isFriend[y][x] = true;
		}

		cout << sol(isPair) << endl;
	}
	return 0;
}