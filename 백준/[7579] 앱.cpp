#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int N, M;
int memory[100];
int cost[100];
int cache[100][10001];  // cache[i][j]: i번째 앱까지 j만큼 비용을 더했을때의 메모리의 최대값

int DP(int current, int total_cost)
{
	if (current >= N) return 0;

	// 메모제이션
	int res = cache[current][total_cost];
	// 탐색한 적이 있으면 종료
	if (res != -1) return res;

	// case1) 현재 앱을 비활성화 시키지 않은 경우
	res = DP(current + 1, total_cost);

	// case2) 현재 앱을 비활성화 시키는 경우
	if (cost[current] <= total_cost)
	{
		//비활성화 시키지 않은 경우와 비교하여 더 큰 메모리인 경우를 저장
		res = max(res, memory[current] + DP(current + 1, total_cost - cost[current]));
	}
	return res;
}

int main()
{
	cin >> N >> M;

	for (int i=0;i<N;i++)
	{
		cin >> memory[i];
	}
	for (int i=0;i<N;i++)
	{
		cin >> cost[i];
	}

	memset(cache, -1, sizeof(cache));

	int ans = 0;
	for (int i=0;i<10001;i++)
	{
		ans=DP(0,i);
		if (ans >= M)
		{
			cout << i;
			break;
		}
	}

	return 0;
}