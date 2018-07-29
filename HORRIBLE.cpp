#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
long long N,C;


void updateTree(long long node, long long a, long long b, long long i, long long j, long long value, vector<long long > &segTree, vector<long long > &lazyTree )
{
	if( a == i && b == j)
	{
		if(lazyTree[node] == 0)
		{
			lazyTree[(2*node)+1] += value;
			lazyTree[(2*node)+2] += value;
			segTree[node] += value;
			return;
		}
		else
		{
			segTree[node] += lazyTree[node];
			lazyTree[node] = 0;
			long long right=0, left=0;
			right = (a + b) / 2;
			left = right + 1;
			updateTree((2*node)+1, a, right, i, j, value, segTree, lazyTree);
			updateTree((2*node)+2, left, b, i, j, value, segTree, lazyTree);
			segTree[node] = segTree[(2*node) + 1] + segTree[(2*node) + 2];
		}
	}
	else if(i > b || j < a)
	{
		return;
	}
	else if( a == b)
	{
		segTree[node] += value;
		return;
	}
	long long right=0, left=0;
	right = (a + b) / 2;
	left = right + 1;
	updateTree((2*node)+1, a, right, i, j, value, segTree, lazyTree);
	updateTree((2*node)+2, left, b, i, j, value, segTree, lazyTree);
	segTree[node] = segTree[(2*node) + 1] + segTree[(2*node) + 2];
}

long long queryTree(long long node, long long a, long long b, long long i, long long j, vector<long long > &segTree, vector<long long > &lazyTree)
{
	if( i > b || j < a )
	{
		return 0;
	}
	else if((a == i && b == j) || (a == b))
	{
		return segTree[node];
	}
	else	
	{
		long long right=0, left=0;
		right = (a + b) / 2;
		left = right + 1;
		long long q1 = queryTree((2*node)+1, a, right, i, j, segTree, lazyTree);
		long long q2 = queryTree((2*node)+2, left, b, i, j, segTree, lazyTree);
		return (q1 + q2); 
	}
}


int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		cin>>N>>C;
		if(N == 0)
			return 0;
		long long ex = log2(N);
		ex += 1;
		long long p = pow(2, ex);
		long long size = (2 * p);
		vector<long long> segTree(size, 0);
		vector<long long> lazyTree(size, 0);
		while(C--)
		{
			long long m, a, b, value;
			cin>>m;
			if(m == 0)
			{
				cin>>a>>b>>value;
				updateTree(0, 0, N-1, a-1, b-1, value, segTree, lazyTree);
			}
			else
			{
				cin>>a>>b;
				cout<<queryTree(0, 0, N-1, a-1, b-1, segTree, lazyTree)<<"\n";
			}
		}
		//cout<<"===================================="<<"\n";
		//for (int i = 0; i < size; ++i)
		//{
		//	cout<<segTree[i]<<" ";
		//}
		//cout<<"\n";
	} 
	return 0;
}