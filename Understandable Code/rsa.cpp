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
	
	cout<<"\n\tEnter Prime No P : ";
	cin>>p;
	 
	cout<<"\n\tEnter Prime No Q : ";
	cin>>q;
	
	
	long long int n = p*q;
	
	
	cout<<"\n\n\t n : "<<n;
	
	long long int e = 2;
	
	long long int phi = (p-1)*(q-1);
	
	
	
	if(phi == 1)
	{
		cout<<"\n\tInvalid Inputs... \n\tphi is 1 !";
		return 0;
	}
	
	while (e < phi)
	{
		// e must be co-prime to phi and
		// smaller than phi.
		if (__gcd(e, phi) ==1)
			break;
		else
			e++;
	}
	
	cout<<"\n\n\t e : "<<e<<"\n";
	
	long long int i = 1;
	
	double exp = phi*i;
	exp = exp + 1;
	exp = exp / e;
	
	while(floor(exp) != exp)
	{
		i++;
		exp = phi*i;
		exp = exp + 1;
		exp = exp/e;
	}
	
	
	long long int d = (long long int)exp;
	
	cout<<"\n\t d : "<<d<<"\n";
	
	int ch;
	
	do
	{
		
		cout<<"\n\n\tSelect Option : \n\
			\n\t 1.Encrypt \n\
			\n\t 2.Decrypt \n\
			\n\t 0.Exit \n";
			
	
	
		cout<<"\n\tEnter Your Choice : ";
		cin>>ch;
		
		if(ch == 0)
			break;
		else if(ch == 1)
		{
			long long int ptext , ctext;
			cout<<"\n\tEnter Plain Text(Number) : ";
			cin>>ptext;
			ctext = power(ptext,n,e);
			cout<<"\n\n\tEncrypted Cipher Text : "<<ctext;
		}
		else if(ch == 2)
		{
			long long int ptext , ctext;
			cout<<"\n\tEnter Cipher Text(Number) : ";
			cin>>ctext;
			ptext = power(ctext,n,d);	
			cout<<"\n\n\tDecrypted Plain Text : "<<ptext;
		}	
		else
		{
			cout<<"\n\t Invalid Choice \n\t Exit....";
			break;
		}
		
	}while(ch!=0);
	
	
	
	return 0;
}
