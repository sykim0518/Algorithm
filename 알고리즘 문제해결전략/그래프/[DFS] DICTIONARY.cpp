/*
1. ���� ������� �ܾ���� �ޱ� ������ makeGraph �Լ����� ���ĺ��� ������ �����ϴ�.

2. ���������� ���ϱ� ���� ��� ���ĺ��� ���� DFS �Լ��� ȣ���մϴ�.

3. DFS�� �����ϸ� ���ĺ��� ������ �������� ����˴ϴ�. ���� algorithm ����� reverse �Լ��� ���� �������� ���� ������� ������ݴϴ�.

4. ���� ����Ŭ�� �����Ѵٸ� ���������� �� ���� �����Ƿ� "INVALID HYPOTHESIS"�� ������ݴϴ�.
*/


#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int C, N;
vector<vector<int>> adj;

/*�׷��� ����*/
// ���ĺ��� �� ���ڿ� ���� ���� ��� ����
// ���� (i,j)�� ���ĺ� i�� j���� �տ� �;����� �ǹ�
void makeGraph(const vector<string>& words)
{
	adj = vector<vector<int>>(26, vector<int>(26, 0));
	for (int j = 1; j < words.size(); j++)
	{
		int i = j - 1;
		int len = min(words[i].size(), words[j].size());

		// words[i]�� words[j] ���� �տ� ���� ������ ã�´�
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

/*DFS�� �̿��� ��������*/
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

/*��������*/
//adj�� �־��� �׷����� ���������� ����� ��ȯ
// �׷����� DAG�� �ƴ϶��, �� ���͸� ��ȯ
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
	// ���� �׷����� DAG�� �ƴ϶��, ���� ����� ������ ������ �ִ�
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