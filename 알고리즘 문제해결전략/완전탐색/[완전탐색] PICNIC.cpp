#include <iostream>
#include <string.h>
using namespace std;

int T;
int N, M;
bool isPair[11][11] = {false};
bool isMatch[11] = { false };

int coutPair(bool isMatch[11])
{
	// 남은 학생 중 가장 번호가 빠른 학생 찾기
	int notMatch = -1;
	for (int i = 0; i < N; i++)
	{
		if (!isMatch[i])
		{
			notMatch = i;
			break;
		}
	}

	// 기저사례: 모든 학생이 짝이 있는 경우
	if (notMatch == -1) return 1;

	int ans = 0;
	for (int i=notMatch+1;i<N;i++)
	{
		if (!isMatch[i] && isPair[notMatch][i])
		{
			isMatch[notMatch] = isMatch[i] = true;
			ans += coutPair(isMatch);
			isMatch[notMatch] = isMatch[i] = false;
		}
	}
	return ans;
}

int main()
{
	cin >> T;
	for (int t=1;t<=T;t++)
	{
		memset(isMatch, false, sizeof(isMatch));
		memset(isPair, false, sizeof(isPair));


		cin >> N >> M;
		for (int m=0;m<M;m++)
		{
			int x, y;
			cin >> x >> y;
			isPair[x][y] = isPair[y][x] = true;
		}
	
		cout<<coutPair(isMatch)<<endl;

	}
	return 0;
}