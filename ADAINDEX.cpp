#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main()
{
	int N,Q;
	cin>>N>>Q;
	struct Trienode
	{
    	Trienode *children[26];
    	int count;
	};
	Trienode start;
	for (int i = 0; i < 26; ++i)
	{
		start.children[i] = NULL;
	}
	start.count = 1;
	for (int i = 0; i < N; ++i)
	{
		string str;
		cin>>str;
		Trienode *prev;
		for (int j = 0; j < str.length(); ++j)
		{
			
			if(j == 0)
				prev = &start;
			if(prev->children[(int)str[j] - (int)'a'] != NULL)
			{
				
				prev = prev->children[(int)str[j] - (int)'a'];
				prev->count += 1;
			}
			else
			{
				Trienode *node = new Trienode;
				for (int k = 0; k < 26; ++k)
				{
					node->children[k] = NULL;
				}
				node->count = 1;
				prev->children[(int)str[j] - (int)'a'] = node;
				//prev->count += 1;
				prev = node;
			}			
		}
	}
	for (int i = 0; i < Q; ++i)
	{
		string str;
		cin>>str;
		Trienode *itr = &start;
		int flag = 0;
		int ans = 0;
		if(str.length() == 0)
		{
			cout<<0<<"\n";
			continue;
		}
		for (int j = 0; j < str.length(); ++j)
		{

			if(itr->children[(int)str[j] - (int)'a'] == NULL)
			{
				ans = 0;
				//cout<<"=============================I WAS HERE===============================\n";
				break;
			}
			else
			{
				itr = itr->children[(int)str[j] - (int)'a'];
				ans = itr->count;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}