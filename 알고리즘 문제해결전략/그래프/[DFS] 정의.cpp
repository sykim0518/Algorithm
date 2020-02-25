#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> adj; // �׷����� ���� ���
vector<bool> visit; // ������ �湮 ����

void DFS(int current)
{
	cout << "�湮����: " << current<<endl;
	visit[current] = true;
	for (int i=0;i<adj[current].size();i++)
	{
		int next = adj[current][i];
		if (!visit[next]) DFS(next);
	}
}

// ��� ������ �湮�ϴ� �Լ�
// : ��� �������� ������ ���� ����Ǿ��ִٴ� ������ ���� ������ ����
void DFSALL()
{
	visit = vector<bool>(adj.size(), false); // �湮 ���θ� ��� �ʱ�ȭ
	for (int i=0;i<adj.size();i++)
	{
		if (!visit[i]) DFS(i);
	}
}

int main()
{
	DFSALL();
	return 0;
}