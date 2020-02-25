/*
1. 사전 순서대로 단어들을 받기 때문에 makeGraph 함수에서 알파벳의 우위를 가립니다.

2. 위상정렬을 구하기 위해 모든 알파벳에 대해 DFS 함수를 호출합니다.

3. DFS를 수행하면 알파벳의 우위가 역순으로 저장됩니다. 따라서 algorithm 헤더의 reverse 함수를 통해 뒤집어준 다음 순서대로 출력해줍니다.

4. 만약 사이클이 존재한다면 위상정렬이 될 수가 없으므로 "INVALID HYPOTHESIS"를 출력해줍니다.
*/


#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int C, N;
vector<vector<int>> adj;

/*그래프 생성*/
// 알파벳의 각 글자에 대한 인접 행렬 생성
// 간선 (i,j)는 알파벳 i가 j보다 앞에 와야함을 의미
void makeGraph(const vector<string>& words)
{
	adj = vector<vector<int>>(26, vector<int>(26, 0));
	for (int j = 1; j < words.size(); j++)
	{
		int i = j - 1;
		int len = min(words[i].size(), words[j].size());

		// words[i]가 words[j] 보다 앞에 오는 이유는 찾는다
		for (int k = 0; k < len; k++)
		{
			if (words[i][k] != words[j][k])
			{
				int a = words[i][k] - 'a';
				int b = words[j][k] - 'a';
				adj[a][b] = 1;
				break;
			}
		}
	}
}

/*DFS를 이용한 위상정렬*/
vector<int> visit;
vector<int> order;

void DFS(int current)
{
	visit[current] = 1;
	
	for (int i = 0; i < adj.size(); i++)
	{
		if (adj[current][i] == 1 && !visit[i]) DFS(i);
	}
	order.push_back(current);
}

/*위상정렬*/
//adj에 주어진 그래프를 위상정렬한 결과를 반환
// 그래프가 DAG이 아니라면, 빈 벡터를 반환
vector<int> topologySort()
{
	int size = adj.size();
	visit = vector<int>(size, 0);
	order.clear();
	for (int i = 0; i < size; i++)
	{
		if (!visit[i]) DFS(i);
	}
	reverse(order.begin(), order.end());
	// 만약 그래프가 DAG이 아니라면, 정렬 결과에 역방향 간선이 있다
	for (int i=0;i<size;i++)
	{
		for (int j=i+1;j<size;j++)
		{
			if (adj[order[j]][order[i]])
				return vector<int>();
		}
	}
	return order;
}

int main()
{
	cin >> C;
	for (int c = 1; c <= C; c++)
	{
		cin >> N;
		vector<string> words(N);
		for (int i = 0; i < N; i++)
		{
			cin>>words[i];
		}
		makeGraph(words);
		vector<int> ans=topologySort();
		if (ans.empty()) cout << "INVALID HYPOTHESIS";
		else {
			for (int i = 0; i < ans.size(); i++)
				cout << (char)(order[i]+'a');
		}
		cout << endl;
	}

	return 0;
}