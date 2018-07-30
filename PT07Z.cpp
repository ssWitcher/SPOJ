#include<iostream>
#include<vector>
#include<stack>
#include<limits>
#include<algorithm>
using namespace std;

int main()
{
	int N;
	cin>>N;
	vector<vector<int> > adj(N+1, vector<int>(N+1));
	stack<int> S;
	for (int i = 1; i < N; ++i)
	{
		int a = 0, b = 0;
		cin>>a>>b;
		adj[a][b] = 1;
		adj[b][a] = 1;
	}
	int len = numeric_limits<int>::min();
	for(int i = 1; i <= N; i++)
	{
		S.push(i);
		
		vector<int> dist(N+1,0);
		while(!S.empty())
		{
			dist[i] = 0;
			for (int j = 1; j <= N; ++j)
			{
				if(adj[S.top()][j] == 1 and visited[j] == 0)
				{
					visited[j] = 1;
					arr[j] = arr[S.top()] + 1;
					S.push(j);
				}
			}				
		}
	}
	cout<<len<<"\n";
	return 0;
}