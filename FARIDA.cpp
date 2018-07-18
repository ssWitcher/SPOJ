#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int T;
	cin>> T;
	for (int s = 0; s < T; ++s)
	{
		int N = 0;	
		cin>>N;
		if(N == 0)
		{
			cout<<"Case "<<s+1<<": "<<0<<"\n";
			continue;
		}
		vector<int> arr(N);
		for (int i = 0; i < N; ++i)
			cin>>arr[i];
		vector<int> ans(N);
		vector<int> filled(N,0);
		for (int i = 0; i < N; ++i)
		{
			if (i == 0)
			{
				ans[i] = arr[i];
				filled[i] = 1;
			}
			else if( i == 1)
			{
				if(arr[1] >= arr[0])
				{
					ans[1] = arr[1];
					filled[1] = 1;
				}
				else
				{
					ans[1] = arr[0];	
				}
			}
			else
			{
				if(filled[i-1] == 0)
				{
					ans[i] = arr[i] + ans[i-1];
					filled[i] = 1;
				}
				else
				{
					int res1 = arr[i] + ans[i-2];
					int res2 = ans[i-1];
					if(res1 >= res2)
					{
						ans[i] = res1;
						filled[i] = 1;
					}
					else
					{
						ans[i] = res2;					
					}
				}
			}
		}
		cout<<"Case "<<s+1<<": "<<ans[N-1]<<"\n";
	} 
	return 0;
}