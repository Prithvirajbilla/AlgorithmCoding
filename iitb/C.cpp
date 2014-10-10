#include <algorithm>
#include <iostream>
#include <iomanip>
#include <complex>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <cstdio>
#include <cmath>
#include <map>
#include <set>
using namespace std;
//#pragma comment(linker,"/STACK:102400000,102400000")
long long gcd(long long a, long long b)
{
if(a == 0 || b == 0)return a + b;
return gcd(b, a % b);
}
int main()
{
int n;
cin >> n;
int g = 0;
for(int i = 1; i <= n; i++)
{
int t;
cin >> t;
g = gcd(g, t);
}
cout << g * n << endl;
return 0;
}