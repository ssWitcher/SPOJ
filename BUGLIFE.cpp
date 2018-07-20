#include<iostream>
#include<vector>
#include<queue>
#include<fstream>
using namespace std;

int main()
{
	int T;
	cin>>T;
	for (int i = 1; i <= T; ++i)
	{
		int n,e;
		cin>>n>>e;
		vector<int> visited(n+1,0);
		vector<char> gender(n+1,'N');
		vector<vector<int> > adj(n+1, vector<int>(n+1));
		int a=0,b=0;
		for (int j = 1; j <= e; ++j)
		{
			cin>>a>>b;
			adj[a][b] = 1;
			adj[b][a] = 1;
		}
		queue<int> Q;
		int flag = 0;
		for (int r = 1; r <= n; ++r)
		{
			if(visited[r] == 0)
			{
				Q.push(r);
				visited[r] = 1;
				gender[r] = 'M';
				while (!Q.empty())
				{
					int curr = Q.front();
					Q.pop();
					for (int s = 1; s <= n; ++s)
					{
						if (adj[curr][s] == 1)
						{
							if(visited[s] == 0)
							{
								Q.push(s);
								visited[s] = 1;
								if ( gender[curr] == 'M')
									gender[s] = 'F';
								else
									gender[s] = 'M';
							}
							else
							{
								if(gender[curr] == gender[s])
								{
									cout<<"Scenario #"<<i<<":\n";
									cout<<"Suspicious bugs found!\n";
									flag = 1;
									break;
								}
							}
						}
					}
					if(flag == 1)
						break;
				}
			}
			if(flag == 1)
					break;
		}
		if(flag != 1)
		{
				cout<<"Scenario #"<<i<<":\n";
				cout<<"No suspicious bugs found!\n";
		}
	}

	return 0;
}
