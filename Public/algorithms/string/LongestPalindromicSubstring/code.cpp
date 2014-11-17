#include <bits/stdc++.h>
using namespace std;
string getHashString(string s)
{
	string st = "#";
	for(int i=0; i<s.length();i++)
	{
		st = st + s[i]+"#";
	}
	return st;
}
void print(int* array,int n,string st)
{
	for(int i=0;i<n;i++)
		cout<<i<<"\t";
	cout<<endl;
	for(int i=0;i<n;i++)
		cout<<st[i]<<"\t";
	cout<<endl;
	for(int i=0; i<n;i++)
		cout<<array[i]<<"\t";
	cout<<endl;
}
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	string str;
	cin>>str;
	string st = getHashString(str);
	int* P = new int[2*n+1];
	fill(P,P+2*n+1,0);
	P[0]=0;
	P[1]=1;
	int C=1;
	int L=0;
	int R=2;
	for(int i=2;i<2*n+1;i++)
	{
		print(P,2*n+1,st);
		cout<<"C : "<<C<<" L : "<<L<<" R: "<<R<<endl;
		int iprime = C-(i-C);

		if(iprime < R-i && iprime >= 0)
		{
			P[i] = P[iprime];
		}
		else
		{

			int answer;
			if(iprime >=0)
				answer= P[iprime];
			else
				answer = 0;
			int smallC = i;
			int k = 0;
			while(smallC-k>=0 && smallC+k <2*n+1 && st[smallC-k] == st[smallC+k])
			{
				k++;
			}
			if(k-1 > 0)
			{
				C=smallC;
				L=smallC-k+1;
				R=smallC+k-1;
				P[i]=k-1;
			}	
		}
	}
	return 0;
}