#include<iostream>
#include<vector>
#include<limits>
using namespace std;

vector<int> arr;
vector<int> segTree;
int N;

void buildTree(int node, int a, int b)
{
	if(node >= ((2*N) - 1))
		return;
	else if( a == b)
	{
		segTree[node] = arr[a];
		return;
	}
	else
	{
		cout<<"Reached Here"<<"\n";
		buildTree(((2*node) + 1), a, ((a+b)/2));
		buildTree(((2*node) + 2), (((a+b)/2)+1), b);
		if(segTree[((2*node) + 1)] >= segTree[((2*node) + 2)])
			segTree[node] = segTree[((2*node) + 1)];
		else
			segTree[node] = segTree[((2*node) + 2)];
		return;
	}
}

int queryTree(int node, int a, int b, int i, int j)
{
	if( i > b || a > j || node >= ((2*N) - 1))
		return numeric_limits<int>::min();
	else if( a >= i && b<=j )
		return segTree[node];
	else
	{
		int q1 = queryTree(((2*node) + 1), a, ((a+b)/2), i, j);
		int q2 = queryTree(((2*node) + 2), (((a+b)/2)+1), b, i, j);
		if(q1 >= q2)
			return q1;
		else
			return q2;
	}
}

int main()
{
	
	cin>>N;
	int value = 0;
	for (int i = 0; i < N; ++i)
	{
		cin>>value;
		arr.push_back(value);
	}
	for (int j = 0; j < ((2*N)-1); ++j)
	{
		segTree.push_back(0);
	}
	buildTree(0,0,N-1);
	int M;
	cin>>M;
	cout<<"Segment tree"<<"\n";
	for (int j = 0; j < ((2*N)-1); ++j)
		cout<<segTree[j]<<" ";
	cout<<"\n";
	for (int i = 0; i < M; ++i)
	{
		int a=0, b=0;
		cin>>a>>b;
		cout<<queryTree(0,0,N-1,a-1,b-1)<<"\n";
	}
	return 0;
}