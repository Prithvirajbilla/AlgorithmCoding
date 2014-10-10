#include <bits/stdc++.h>
using namespace std;
#define mod 1000000009
#define ll long long int
pair<int,int> colors[1000000];
struct less_than_key
{
    inline bool operator() (const pair<int,int>& s1, const pair<int,int>& s2)
    {
        return (s1.second < s2.second);
    }
};
int readInt () {
	bool minus = false;
	int result = 0;
	char ch;
	ch = getchar();
	while (true) {
		if (ch == '-') break;
		if (ch >= '0' && ch <= '9') break;
		ch = getchar();
	}
	if (ch == '-') minus = true; else result = ch-'0';
	while (true) {
		ch = getchar();
		if (ch < '0' || ch > '9') break;
		result = result*10 + (ch - '0');
	}
	if (minus)
		return -result;
	else
		return result;
}
 
void quickSort(pair<int,int> arr[], int left, int right) {

      int i = left, j = right;

      pair<int,int> tmp;

      int pivot = arr[(left + right) / 2].second;

 

      /* partition */

      while (i <= j) {

            while (arr[i].second < pivot)

                  i++;

            while (arr[j].second > pivot)

                  j--;

            if (i <= j) {

                  tmp = arr[i];

                  arr[i] = arr[j];

                  arr[j] = tmp;

                  i++;

                  j--;

            }

      };

 

      /* recursion */

      if (left < j)

            quickSort(arr, left, j);

      if (i < right)

            quickSort(arr, i, right);

}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		// cin>>n>>m;
		n= readInt();
		m = readInt();
		for (int i = 0; i < m; ++i)
		{
			char c;int a;
			cin>>c;
			a = readInt();
			colors[i] = make_pair(c-'A',a);
		}
		ll result = 1;
		quickSort(colors,0,m-1);
		int kk = 1;int previous = 0;
		while(kk < m)
		{
			while(kk < m && colors[previous].first == colors[kk].first)
			{
				kk++;
			}
			if(kk == m)
			{
				break;
			}
			result *= (colors[kk].second-colors[kk-1].second);
			result %= mod;
			previous = kk;
			kk++;
		}
		cout<<result<<endl;
	}
	return 0;
}