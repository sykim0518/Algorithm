#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> adj; // 그래프의 인접 행렬
vector<bool> visit; // 정점의 방문 여부

void DFS(int current)
{
	cout << "방문정점: " << current<<endl;
	visit[current] = true;
	for (int i=0;i<adj[current].size();i++)
	{
		int next = adj[current][i];
		if (!visit[next]) DFS(next);
	}
}

// 모든 정점을 방문하는 함수
// : 모든 정점들이 간선을 통해 연결되어있다는 보장이 없기 때문에 구현
void DFSALL()
{
	visit = vector<bool>(adj.size(), false); // 방문 여부를 모두 초기화
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