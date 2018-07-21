#include<iostream>
#include<vector>
#include<queue>
#include<cstdio>
using namespace std;

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		vector<vector<int> > board(8, vector<int>(8));
		struct Pos
		{
			int x;
			int y;
		};
		Pos point1, point2, point3, point4,point5,point6,point7, point8, start, curr;
		queue<Pos> Q;
		char a,b;
		int srcX, dstX;
		cin>>a>>srcX>>b>>dstX;
		int srcY = (int)(a - 'a');
		int dstY = (int)(b - 'a');
		srcX = 8 - srcX;
		dstX = 8 - dstX; 
		start.x = srcX;
		start.y = srcY; 
		Q.push(start);
		board[start.x][start.y] = 1;
		//cout<<"The value of start : "<<start.x<<" "<<start.y<<"\n"; 
		//cout<<"Comes here\n";
		while( !Q.empty())
		{
			curr = Q.front();
			Q.pop();
			point1.x = curr.x + 2;
			point1.y = curr.y + 1;
			point2.x = curr.x + 2;
			point2.y = curr.y - 1;
			point3.x = curr.x - 2;
			point3.y = curr.y - 1;
			point4.x = curr.x - 2;
			point4.y = curr.y + 1;
			point5.x = curr.x + 1;
			point5.y = curr.y + 2;
			point6.x = curr.x + 1;
			point6.y = curr.y - 2;
			point7.x = curr.x - 1;
			point7.y = curr.y - 2;
			point8.x = curr.x - 1;
			point8.y = curr.y + 2;
			if(point1.x <= 7 && point1.x >= 0 && point1.y <= 7 && point1.y >= 0 && (board[point1.x][point1.y] == 0))
			{
				board[point1.x][point1.y] = board[curr.x][curr.y] + 1;
				Q.push(point1);
				//cout<<"The value of point1 : "<<point1.x<<" "<<point1.y<<"\n";
			}
			if(point2.x <= 7 && point2.x >= 0 && point2.y <= 7 && point2.y >= 0 && (board[point2.x][point2.y] == 0))
			{
				board[point2.x][point2.y] = board[curr.x][curr.y] + 1;
				Q.push(point2);
				//cout<<"The value of point2 : "<<point2.x<<" "<<point2.y<<"\n";
			}
			if(point3.x <= 7 && point3.x >= 0 && point3.y <= 7 && point3.y >= 0 && (board[point3.x][point3.y] == 0))
			{
				board[point3.x][point3.y] = board[curr.x][curr.y] + 1;
				Q.push(point3);
				//cout<<"The value of point3 : "<<point3.x<<" "<<point3.y<<"\n";
			}
			if(point4.x <= 7 && point4.x >= 0 && point4.y <= 7 && point4.y >= 0 && (board[point4.x][point4.y] == 0))
			{
				board[point4.x][point4.y] = board[curr.x][curr.y] + 1;
				Q.push(point4);
				//cout<<"The value of point4 : "<<point4.x<<" "<<point4.y<<"\n";
			}
			if(point5.x <= 7 && point5.x >= 0 && point5.y <= 7 && point5.y >= 0 && (board[point5.x][point5.y] == 0))
			{
				board[point5.x][point5.y] = board[curr.x][curr.y] + 1;
				Q.push(point5);
				//cout<<"The value of point5 : "<<point5.x<<" "<<point5.y<<"\n";
			}
			if(point6.x <= 7 && point6.x >= 0 && point6.y <= 7 && point6.y >= 0 && (board[point6.x][point6.y] == 0))
			{
				board[point6.x][point6.y] = board[curr.x][curr.y] + 1;
				Q.push(point6);
				//cout<<"The value of point6 : "<<point6.x<<" "<<point6.y<<"\n";
			}
			if(point7.x <= 7 && point7.x >= 0 && point7.y <= 7 && point7.y >= 0 && (board[point7.x][point7.y] == 0))
			{
				board[point7.x][point7.y] = board[curr.x][curr.y] + 1;
				Q.push(point7);
				//cout<<"The value of point7 : "<<point7.x<<" "<<point7.y<<"\n";
			}
			if(point8.x <= 7 && point8.x >= 0 && point8.y <= 7 && point8.y >= 0 && (board[point8.x][point8.y] == 0))
			{
				board[point8.x][point8.y] = board[curr.x][curr.y] + 1;
				Q.push(point8);
				//cout<<"The value of point8 : "<<point8.x<<" "<<point8.y<<"\n";
			}

		}
		cout<<board[dstX][dstY] - 1<<"\n";
	} 
	return 0;
}