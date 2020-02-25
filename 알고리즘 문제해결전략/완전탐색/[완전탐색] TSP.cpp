#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int T;
int N;
double map[9][9];

vector<int> path; // 지금까지 만든 경로
bool visit[9] = {false};// 각도시의 방문 여부
double currentLength = 0; // 지금까지 만든 경로의 길이

double shortestPath(vector<int> path, bool visit[9], double currentLength)
{
	// 기저사례 : 모든 도시를 다 방문했을 경우, 시작 도시로 돌아가고 종료
	if (path.size() == N)
	{
		return currentLength + map[path[0]][path.back()];
	}

	double ret = 999999999;
	for (int next=0;next<N;next++)
	{
		if (visit[next]) continue;
		int current = path.back();
		path.push_back(next);
		visit[next] = true;
		double cand = shortestPath(path, visit, currentLength + map[current][next]);
		ret = min(ret, cand);
		visit[next] = false;
		path.pop_back();
	}
	return ret;
}

int main()
{
	cin >> T;
	for (int t=1;t<=T;t++)
	{
		memset(map, 0, sizeof(map));
		memset(visit, false, sizeof(visit));
		currentLength = 0;
		path.clear();

		cin >> N;
		for (int i=0;i<N;i++)
		{
			for (int j=0;j<N;j++)
			{
				cin >> map[i][j];
			}
		}

		path.push_back(0);
		visit[0] = true;
		cout<<shortestPath(path, visit, currentLength)<<endl;

	}
	return 0;
}