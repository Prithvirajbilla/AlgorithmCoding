#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	char* array = new char[n+1];
	for (int i = 1; i <= n; ++i)
	{
		cin>>array[i];
	}
	bool new_array = true;
	bool has_found_r = false;
	bool has_found_l = false;
	int start=-1;int end = -1;
	for (int i = 1; i <= n; ++i)
	{
		if(array[i] == 'L' && !has_found_l && !has_found_r)
		{
			has_found_l = true;
			end = i-1;
		}
		else if(has_found_l == true && !has_found_r && array[i] == '.')
		{
			start = i-1;
			break;
		}
		if(array[i] == 'R' && !has_found_r)
		{
			has_found_r = true;
			start = i;
		}
		else if(has_found_r == true && array[i] == 'L')
		{
			end = i-1;
			break;
		}
		else if(has_found_r == true && array[i] == '.')
		{
			end = i;
			break;
		}
	}
	if(has_found_l && start == -1)
	{	
		start = max(start,n);
	}
	if(has_found_r && end == -1)
	end = max(end,n);

	cout<<start<<" "<<end<<endl;
	return 0;
}