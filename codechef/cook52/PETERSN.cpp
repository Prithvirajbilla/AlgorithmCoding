#include <bits/stdc++.h>
using namespace std;
string s;		   //0,1,2,3,4,5,6,7,8,9	
int ptsn[10][10] = {{0}};
vector<vector<int> > q(10,vector<int>(10));
void fill()
{
	ptsn[0][5] = 1;ptsn[0][1]=1;ptsn[0][4]= 1;
	ptsn[1][2] = 1;ptsn[1][0]=1;ptsn[1][6]=1;
	ptsn[2][3] = 1;ptsn[2][1]=1;ptsn[2][7]=1;
	ptsn[3][4] = 1;ptsn[3][2]= 1;ptsn[3][8]=1;
	ptsn[4][0] = 1;ptsn[4][3]= 1;ptsn[4][9]=1;
	ptsn[5][0] = 1;ptsn[5][7] = ptsn[5][8]=1;
	ptsn[6][1] =   ptsn[6][9] = ptsn[6][8]=1;
	ptsn[7][9] =   ptsn[7][5] = ptsn[7][2]=1;
	ptsn[8][6] =   ptsn[8][5] = ptsn[8][3]=1;
	ptsn[9][4] = 1;ptsn[9][6] =1;ptsn[9][7]=1;

	q[0][0]=0;	q[0][1]=5;
	q[1][0]=1;	q[1][1]=6;
	q[2][0]=2;	q[2][1]=7;
	q[3][0]=3;	q[3][1]=8;
	q[4][0]=4;	q[4][1]=9;

}
int main()
{
	fill();

	int t;
	cin>>t;
	while(t--)
	{
		cin>>s;
		string s1;
		int st = q[s[0]-'A'][0];
		s1.push_back(st+'0');
		for (int i = 1; i < s.length(); ++i)
		{
			bool is_comp = true;
			int now_node = s[i]-'A';
			for(int j=0; j < 10; j++)
			{
				if(ptsn[st][j] == 1 && q[now_node][0] == j)
				{
					st = j;
					s1.push_back(st+'0');
					is_comp = false;
					break;
				}
				else if(ptsn[st][j] == 1 &&  q[now_node][1] == j)
				{
					st = j;
					s1.push_back(st+'0');
					is_comp = false;
					break;
				}
			}
			if(is_comp)
				break;
		}

		st = q[s[0]-'A'][1];
		string s2;
		s2.push_back(st+'0');
		for (int i = 1; i < s.length(); ++i)
		{
			bool is_comp = true;
			int now_node = s[i]-'A';
			for(int j=0; j < 10; j++)
			{
				if(ptsn[st][j] == 1 && q[now_node][0] == j)
				{
					st = j;
					s2.push_back(st+'0');
					is_comp = false;
					break;
				}
				else if(ptsn[st][j] == 1 &&  q[now_node][1] == j)
				{
					st = j;
					s2.push_back(st+'0');
					is_comp = false;
					break;
				}
			}
			if(is_comp)
				break;
		}
		vector<string> asd;
		
		if(s1.length() == s.length()) asd.push_back(s1);
		
		if(s2.length() == s.length()) asd.push_back(s2);
		
		sort(asd.begin(),asd.end());
		
		if(asd.size() == 0)
			cout<<-1<<endl;
		else
			cout<<asd[0]<<endl;
	}
	return 0;
}