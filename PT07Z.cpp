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
	vector<int> visited(N+1,0);
	vector<int> toStartNodes;
	stack<int> S;
	for (int i = 1; i < N; ++i)
	{
		int a = 0, b = 0;
		cin>>a>>b;
		adj[a][b] = 1;
		adj[b][a] = 1;
		cout<<"FINE\n";
	}
	for (int i = 1; i <= N; ++i)
	{
		int count = 0;
		for (int j = 1; j <= N; ++j)
		{
			if(adj[i][j] == 1)
				count++;
		}
		cout<<"NOT FINE\n";
		if(count == 1)
			toStartNodes.push_back(i);
	}
	int len = numeric_limits<int>::min();

	for(int i = 0; i < toStartNodes.size(); i++)
	{
		
		int flag = 0;
		cout<<"DEBUG 1\n";
		S.push(toStartNodes[i]);
		visited[toStartNodes[i]] = 1;
		while(!S.empty())
		{
			cout<<"DEBUG 2\n";
			vector<int> arr(N+1);
			arr[toStartNodes[i]] = 0;
			for (int j = 1; j <= N; ++j)
			{
				if(adj[S.top()][j] == 1 and visited[j] == 0)
				{
					visited[j] = 1;
					cout<<"DEBUGGER"<<"\n";
					arr[j] = arr[S.top()] + 1;
					S.push(j);
				}
				else
				{
					S.pop();
				}
			}
			int res = numeric_limits<int>::min();
			for (int k = 1; k <= N; ++k)
			{
				if ( res <= arr[k])
					res = arr[k];
			}
			if( len <= res )
			{
				len = res;
			}
		}
	}
	cout<<"DEBUG 3\n";
	cout<<len<<"\n";
	return 0;
}