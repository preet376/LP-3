#include<iostream>
#include<math.h>
#include<vector>
using namespace std;

vector<int> point(int a,int b)
{
	int rhs,lhs,y;
	vector<int> v;
	if((4*(a*a*a) + 27*(b*b)) != 0)
	{
		int x = 1;
		while(1)
		{
			rhs = (x*x*x) + a*x + b;
			y = (int)sqrt(rhs);
			lhs = y*y;
			
			if(lhs == rhs)
			{
				v.push_back(x);
				v.push_back(y);
				return v;
			}
			else
			{
				x++;
			}
		}
	}
	else
	{
		cout<<"Invalid";
		return v;
	}
}

int main()
{
	int a,b;
	cin>>a;
	cin>>b;
	
	int private_A = 13;
	int private_B = 15;
	vector<int> public_A;
	vector<int> public_B;
	vector<int> generator;
	vector<int> cipher;
	generator = point(a,b);
	cout<<generator[0]<<endl;
	cout<<generator[1]<<endl;
	
	long int m;
	cout<<"Enter the Plaintext"<<endl;
	cin>>m;
    
    public_A.push_back(private_A*generator[0]);
    public_A.push_back(private_A*generator[1]);
    
    cout<<public_A[0]<<" "<<public_A[1];
    
    public_B.push_back(private_B*generator[0]);
    public_B.push_back(private_B*generator[1]);
    
    cout<<public_B[0]<<" "<<public_B[1];
    
    int k = rand()%10+1;
    
    int c1 = k*(generator[0]+generator[1]);
    int c2 = m + (k*public_B[0]+k*public_B[1]);
    
    cipher.push_back(c1);
    cipher.push_back(c2);
    
    cout<<"Ciphertext is "<<cipher[0]<<" "<<cipher[1];
    
    int r = private_B*c1;
    int plaintext = c2-r;
    
    cout<<"Decrypted Plaintext is "<<plaintext;
    
	return 0;
}
