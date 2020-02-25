#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int N, M;
int memory[100];
int cost[100];
int cache[100][10001];  // cache[i][j]: i��° �۱��� j��ŭ ����� ���������� �޸��� �ִ밪

int DP(int current, int total_cost)
{
	if (current >= N) return 0;

	// �޸����̼�
	int res = cache[current][total_cost];
	// Ž���� ���� ������ ����
	if (res != -1) return res;

	// case1) ���� ���� ��Ȱ��ȭ ��Ű�� ���� ���
	res = DP(current + 1, total_cost);

	// case2) ���� ���� ��Ȱ��ȭ ��Ű�� ���
	if (cost[current] <= total_cost)
	{
		//��Ȱ��ȭ ��Ű�� ���� ���� ���Ͽ� �� ū �޸��� ��츦 ����
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