#include<iostream>
#include<vector>
#include<queue>
#include<fstream>
using namespace std;

int main()
{
	int T;
	vector<int> n,e;
        ifstream inFile;
        char inputFilename[] = "in.list";
        inFile.open(inputFilename, ios::in);
        if (!inFile)
        {
                cerr << "Can't open input file " << inputFilename << endl;
                exit(1);
        }
	int a=0,b=0;
	cout<<"about to read the input file\n";
        while (!inFile.eof())
        {
                inFile >> a  >> b;
		n.push_back(a);
		e.push_back(b);
        }
	cout<<"read input\n";
	cout<<"the size of n is : "<<n.size()<<"\n";
	T=n[0];
	for (int i = 1; i <= T; ++i)
	{
		vector<int> visited(n[i]+1,0);
		vector<char> gender(n[i]+1,0);
		vector<vector<int> > adj(n[i]+1, vector<int>(n[i]+1));
		a=0,b=0;
		for (int j = 1; j <= e[i]; ++j)
		{
			cin>>a>>b;
			adj[a][b] = 1;
		}
		queue<int> Q;
		int flag = 0;
		for (int r = 1; r <= n[i]; ++r)
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
					for (int s = 1; s <= n[i]; ++s)
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
