#include<bits/stdc++.h>
using namespace std;

long long int power(long long  int p,long long  int q ,long long int x)
{
	if(x>10)
	{
		long long int y = x - 10;
		return (power(p,q,10) * power(p,q,y))%q ;		
	}
	
	return ( ((long long int)pow(p,x))% q );
}


int main()
{
	
	
	long long int p,q;
	long long int a,b;
	
	cout<<"\n\tEnter P : ";
	cin>>p;
	
	cout<<"\n\tEnter Q : ";
	cin>>q;
	
	cout<<"\n\tEnter a for Sender : ";
	cin>>a;
	
	cout<<"\n\tEnter b for Receiver : ";
	cin>>b;
	
	long long int A,B;
	
	A = power(p,q,a);
	B = power(p,q,b);
	
	cout<<"\n\tA : "<<A;
	cout<<"\n\tB : "<<B;
	
	long long int S1,S2;
	
	S1 = power(B,q,a);
	S2 = power(A,q,b);
	
	
	cout<<"\n\n\tSecret Keys : ";
	cout<<"\n\tS1 : "<<S1;
	cout<<"\n\tS2 : "<<S2;
	
	
	return 0;
}
