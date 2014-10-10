#include <bits/stdc++.h>
using namespace std;
#define log2  0.30102999566398119521373889472449L
long long int modpow(long long int a,long long b)
{
	if(a == 1) return 2;
	else if(a%2 == 1)
	{
		long long int temp = modpow(a/2 , b);
		return (2*temp*temp)%b;
	}
	else
	{
		long long int temp = modpow(a/2 , b);
		return (temp*temp)%b;
	}
}
long int firstKdigits(long long n,int k)

{ 
	long double x, y;
	x = n*log2;
	y = floor(pow(10,x-floor(x) +k-1));
	return ((int)(ceil(y)));
}
int main(int argc, char const *argv[])
{
	int T;
	cin>>T;
	for (int i = 0; i < T; ++i)
	{
		long long int n,k;
		cin>>n>>k;
        n-=1;
		long long int lst = modpow(n,pow(10,k));
		long long int fst = firstKdigits(n,k);
		cout<<lst+fst<<endl;
	}
	return 0;
}