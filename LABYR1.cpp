#include<iostream>
#include<vector>
#include<stack>
#include<limits>
using namespace std;

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int C=0, R=0;
		cin>>C>>R;
		struct point
		{
			int x;
			int y;
		};
		cout<<"The value of C and R is "<<C<<" "<<R<<"\n"; 
		vector<vector<char > > arr(C, vector<char >(R,0));
		vector<vector<int > > visited(C, vector<int >(R,0));
		vector<point > startPoints;
		for (int i = 0; i < R; ++i)
		{
			for (int j = 0; j < C; ++j)
			{
				cin>>arr[i][j];
				struct point startPoint;
				if(arr[i][j] == '.')
				{
					startPoint.x = i;
					startPoint.y = j;
					startPoints.push_back(startPoint);
				}
			}
		}
		stack<struct point > S;
		for (int i = 0; i < startPoints.size(); ++i)
		{
			S.push(startPoints[i]);
			while(!S.empty())
			{
			 struct point ab, pushPoint;
			 ab = S.top();
			 int flag = 0;

			 if(ab.x + 1 < R && (visited[ab.x + 1][ab.y] == 0) && arr[ab.x+1][ab.y] == '.')
			 {
			 	pushPoint.x = ab.x + 1;
			 	pushPoint.y = ab.y;
			 	S.push(pushPoint);
			 	visited[pushPoint.x][pushPoint.y] = visited[ab.x][ab.y] + 1;
			 	flag = 1;
			 }

			 if( ab.x - 1 >= 0 && (visited[ab.x - 1][ab.y] == 0) && arr[ab.x-1][ab.y] == '.')
			 {
			 	pushPoint.x = ab.x - 1;
			 	pushPoint.y = ab.y;
			 	S.push(pushPoint);
			 	visited[pushPoint.x][pushPoint.y] = visited[ab.x][ab.y] + 1;
			 	flag = 1;	
			 }	

			 if(ab.y + 1 < C && (visited[ab.x][ab.y + 1] == 0) && arr[ab.x][ab.y + 1] == '.')
			 {
			 	pushPoint.x = ab.x;
			 	pushPoint.y = ab.y + 1;
			 	S.push(pushPoint);
			 	visited[pushPoint.x][pushPoint.y] = visited[ab.x][ab.y] + 1;
			 	flag = 1;
			 }

			 if(ab.y - 1 >= 0 && (visited[ab.x][ab.y - 1] == 0) && arr[ab.x][ab.y + 1] == '.')
			 {
			 	pushPoint.x = ab.x;
			 	pushPoint.y = ab.y - 1;
			 	S.push(pushPoint);
			 	visited[pushPoint.x][pushPoint.y] = visited[ab.x][ab.y] + 1;
			 	flag = 1;
			 }
			 if(flag == 0)
			 {
			 	S.pop();
			 }
		 
			}
		}
		int len = numeric_limits<int>::min();
		cout<<"==========================Visited Array==================================="<<"\n";
		for (int i = 0; i < R; ++i)
		{
			for (int j = 0; i < C; ++i)
			{
				cout<<visited[i][j]<<" ";
			}
			cout<<"\n";
		}
		for (int i = 0; i < R; ++i)
		{
			for (int j = 0; i < C; ++i)
			{
				if(len <= visited[i][j])
					len = visited[i][j];
			}
		}
		cout<<"Maximum rope length is "<<len<<"\n";
	} 
	return 0;
}