#include<iostream>
#include<vector>
using namespace std;

int gcd(int a, int b)
{
    return (a%b == 0)? abs(b) : gcd(b,a%b);
}


int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int a, b, c;
		if((c % gcd(a,b)) == 0)
		{
			
		}
		else
		{
			cout<<-1<<"\n";
		}
	} 
	return 0;
}